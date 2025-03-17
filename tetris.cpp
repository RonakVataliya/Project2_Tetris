#include <iostream>
#include <vector>
#include <fstream> // For saving high score
#include <windows.h>
#include <conio.h>
#include <ctime>

using namespace std;

const int WIDTH = 10;
const int HEIGHT = 20;
const int INITIAL_DROP_SPEED = 500; // Initial drop speed in milliseconds
const int SPEED_INCREASE_RATE = 10; // 10% increase every few pieces
const int PIECES_BEFORE_SPEEDUP = 5; // Number of tetrominoes before speed increases
const string HIGH_SCORE_FILE = "highscore.txt";

vector<vector<vector<int>>> TETROMINOES = {
    {{1, 1, 1, 1}}, {{1, 1}, {1, 1}}, {{0, 1, 0}, {1, 1, 1}},
    {{0, 1, 1}, {1, 1, 0}}, {{1, 1, 0}, {0, 1, 1}}, 
    {{1, 0, 0}, {1, 1, 1}}, {{0, 0, 1}, {1, 1, 1}}
};

class Tetromino {
public:
    vector<vector<int>> shape;
    int x, y;

    Tetromino(vector<vector<int>> s) : shape(s), x(WIDTH / 2 - s[0].size() / 2), y(0) {}

    void rotate() {
        int rows = shape.size(), cols = shape[0].size();
        vector<vector<int>> rotated(cols, vector<int>(rows, 0));

        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                rotated[j][rows - 1 - i] = shape[i][j];

        shape = rotated;
    }
};

class Game {
private:
    vector<vector<int>> grid;
    Tetromino* currentPiece;
    int score;
    int highScore;
    int dropSpeed;
    int piecesPlaced;
    bool gameOver;
    bool paused;
    HANDLE hConsole;
    DWORD lastDropTime;

    bool checkCollision(const Tetromino& piece) {
        for (int i = 0; i < piece.shape.size(); ++i) {
            for (int j = 0; j < piece.shape[i].size(); ++j) {
                if (piece.shape[i][j]) {
                    int newX = piece.x + j, newY = piece.y + i;
                    if (newX < 0 || newX >= WIDTH || newY >= HEIGHT || (newY >= 0 && grid[newY][newX])) 
                        return true;
                }
            }
        }
        return false;
    }

    void mergePiece(const Tetromino& piece) {
        for (int i = 0; i < piece.shape.size(); ++i) {
            for (int j = 0; j < piece.shape[i].size(); ++j) {
                if (piece.shape[i][j]) 
                    grid[piece.y + i][piece.x + j] = 1;
            }
        }
        piecesPlaced++;
        if (piecesPlaced % PIECES_BEFORE_SPEEDUP == 0) {
            increaseSpeed();
        }
    }

    void clearLines() {
        int linesCleared = 0;
        for (int i = HEIGHT - 1; i >= 0; i--) {
            bool full = true;
            for (int j = 0; j < WIDTH; j++) {
                if (!grid[i][j]) {
                    full = false;
                    break;
                }
            }
            if (full) {
                linesCleared++;
                for (int k = i; k > 0; k--) 
                    grid[k] = grid[k - 1];
                grid[0] = vector<int>(WIDTH, 0);
                i++;
            }
        }
        score += linesCleared * 100;
        if (score > highScore) {
            highScore = score;
            saveHighScore();
        }
    }

    void setCursorPosition(int x, int y) {
        COORD position = { (SHORT)x, (SHORT)y };
        SetConsoleCursorPosition(hConsole, position);
    }

    void hideCursor() {
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(hConsole, &cursorInfo);
        cursorInfo.bVisible = false;
        SetConsoleCursorInfo(hConsole, &cursorInfo);
    }

    void loadHighScore() {
        ifstream file(HIGH_SCORE_FILE);
        if (file.is_open()) {
            file >> highScore;
            file.close();
        } else {
            highScore = 0; // Default to 0 if file does not exist
        }
    }

    void saveHighScore() {
        ofstream file(HIGH_SCORE_FILE);
        if (file.is_open()) {
            file << highScore;
            file.close();
        }
    }

    void increaseSpeed() {
        dropSpeed = max(50, dropSpeed - dropSpeed * SPEED_INCREASE_RATE / 100); // Min speed cap at 50ms
    }

public:
    Game() : grid(HEIGHT, vector<int>(WIDTH, 0)), score(0), gameOver(false), paused(false), piecesPlaced(0) {
        srand(static_cast<unsigned>(time(0)));
        currentPiece = new Tetromino(TETROMINOES[rand() % TETROMINOES.size()]);
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        hideCursor();
        lastDropTime = GetTickCount();
        dropSpeed = INITIAL_DROP_SPEED;
        loadHighScore();
    }

    ~Game() {
        delete currentPiece;
    }

    void handleInput() {
        if (_kbhit()) {
            char key = _getch();
            Tetromino temp = *currentPiece;
            switch (key) {
                case 'a': case 75: temp.x--; break;
                case 'd': case 77: temp.x++; break;
                case 's': case 80: temp.y++; break;
                case 'w': case 72: temp.rotate(); break;
                case ' ': while (!checkCollision(temp)) temp.y++; temp.y--; break;
                case 'p': paused = !paused; break;
                case 27: gameOver = true; break;
                case 'r': restart(); break;
            }
            if (!checkCollision(temp)) *currentPiece = temp;
        }
    }

    void update() {
        if (paused || gameOver) return;

        DWORD currentTime = GetTickCount();
        if (currentTime - lastDropTime >= dropSpeed) {
            Tetromino temp = *currentPiece;
            temp.y++;
            if (checkCollision(temp)) {
                mergePiece(*currentPiece);
                clearLines();
                delete currentPiece;
                currentPiece = new Tetromino(TETROMINOES[rand() % TETROMINOES.size()]);
                if (checkCollision(*currentPiece)) gameOver = true;
            } else {
                *currentPiece = temp;
            }
            lastDropTime = currentTime;
        }
    }

    void render() {
        setCursorPosition(0, 0);
        for (int i = 0; i < HEIGHT; ++i) {
            cout << " |"; 
            for (int j = 0; j < WIDTH; ++j) {
                bool isPieceBlock = false;
                for (int pi = 0; pi < currentPiece->shape.size(); ++pi) {
                    for (int pj = 0; pj < currentPiece->shape[pi].size(); ++pj) {
                        if (currentPiece->shape[pi][pj] && i == currentPiece->y + pi && j == currentPiece->x + pj) {
                            isPieceBlock = true;
                            break;
                        }
                    }
                }
                cout << (isPieceBlock || grid[i][j] ? "[]" : "  ");
            }
            cout << "|\n";
            
        }
        cout << " |";
        for (int i = 0; i < 2*WIDTH; ++i) cout << "_";
        cout << "|\n";
        cout << "Score: " << score << "  |  High Score: " << highScore << "  |  Speed: " << dropSpeed << "ms\n";
        if (gameOver) cout << "Game Over! Press 'R' to Restart\n";
    }

    bool isGameOver() const { return gameOver; }

    void restart() {
        gameOver = false;
        score = 0;
        piecesPlaced = 0;
        dropSpeed = INITIAL_DROP_SPEED;
        grid = vector<vector<int>>(HEIGHT, vector<int>(WIDTH, 0));
        delete currentPiece;
        currentPiece = new Tetromino(TETROMINOES[rand() % TETROMINOES.size()]);
    }
};
int main() {
    while (true) {
        Game game;
        while (!game.isGameOver()) {
            game.handleInput();
            game.update();
            game.render();
            Sleep(50);
        }
        cout << "Press 'R' to Restart or 'ESC' to Quit\n";
        while (true) {
            char c = _getch();
            if (c == 'r' || c == 'R') break;
            if (c == 27) return 0; // Exit game on ESC key
        }
    }
}