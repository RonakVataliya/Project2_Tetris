# 🎮 Tetris Game in C++ 🧩🚀

## Student ID 🆔📚🎓  
- *Vataliya Ronak: 202401241*  
- *Tolani Dhaval: 202401228*
- *Taksh Chauhan: 202401223*
- *Vikas Soni: 202401214*

## Table of Contents 📑🔍🗂    
1. Overview  
2. Requirements
3. Data Structures Used
4. Data Members
5. How to Compile  
6. How to Run
7. GAmeplay Roadmap
8. Game Controls
9. Key Features 
10. Files
11. Code Highlights
12. Limitations
13. Possible Enhancements 
14. License
15. Contact


## 🎯 Overview ✨📝
This is a console-based implementation of the classic Tetris game written in C++. It features:

- Real-time gameplay with keyboard controls.
- Progressive speed increase as the game progresses.
- High score tracking saved to a file.

## 🖥️ Requirements 🔧⚡
- 🪟 Windows OS (due to usage of Windows-specific headers like `<windows.h>` and `_kbhit()` for keyboard input).
- 🛠️ A C++ compiler that supports C++11 or higher (e.g., MinGW, MSVC).

# Data Structures Used 🗂

- *vector<vector<int>>*: Stores the game grid and individual Tetromino shapes.  
- *vector<vector<vector<int>>*: Holds predefined Tetromino shapes.  
- *Tetromino (Class)*: Represents a falling piece with its shape, position, and color.  
- *Game (Class)*: Manages game logic, user input, rendering, and score tracking. 

## Data Members:
- grid: 2D vector representing the game board.
- currentPiece: Stores the currently active Tetromino.
- score: Tracks the player's score.
- highScore: Stores the highest recorded score.
- speed: Controls the drop speed of Tetrominoes.
- isGameOver: Boolean flag to indicate the end of the game.

## 🏗️ How to Compile 🖱️💻
Use the following command to compile the game (assuming `g++` is installed):

```bash
g++ -o tetris tetris.cpp
```

## 🚀 How to Run 📂⚙️
Run the compiled executable:

```bash
./tetris
```

## Gameplay Roadmap

- main()
 - ├── Game()
 - │    ├── hideCursor()
 - │    ├── loadHighScore()
 - │    └── Tetromino()  // Creates the first piece
 - ├── while (!game.isGameOver())
 - │    - ├── game.handleInput()
 - │    - │    - ├── checkCollision() // For movement validation
 - │    - │    - ├── rotate() // If user presses 'w' or Up Arrow
 - │    - │    - ├── restart() // If user presses 'r'
 - │    - ├── game.update()
 - │    - │    - ├── checkCollision() // To detect landing
 - │    - │    - ├── mergePiece() // If piece lands
 - │    - │    - │    -├── increaseSpeed() // Every 5 pieces
 - │    - │    - ├── clearLines() // If lines are full
 - │    - │    - │    -├── saveHighScore() // If score is higher
 - │    - │    - ├── Tetromino() // Create a new piece
 - │    - │    - ├── checkCollision() // If new piece immediately collides
 - │    - ├── game.render()
 - ├── If gameOver
 - │    - ├── Wait for 'R' or 'ESC'
 - │    - ├── restart() // If 'R'
 - │    - └── return 0 // If 'ESC'

## 🎮 Game Controls 🕹️🔄
| Key      | Action                     |
|----------|----------------------------|
| `A` or Left Arrow | 🔙 Move piece left            |
| `D` or Right Arrow| 🔜 Move piece right           |
| `S` or Down Arrow | ⬇️ Move piece down faster     |
| `W` or Up Arrow   | 🔄 Rotate the piece           |
| `Space`           | ⬇️ Drop piece instantly       |
| `P`               | ⏸️ Pause/Unpause the game     |
| `R`               | 🔄 Restart the game           |
| `ESC`             | ❌ Quit the game              |


## 🌟  Key Features 🚀🎮
- ⚡ *Dynamic Speed Adjustment:*
    - 🚀 The drop speed of the tetrominoes increases by 10% after every 5 pieces placed, with a minimum speed cap of 50ms. ⚡⏱📈
- 🏆 *High Score Tracking:*
    - 📄 The highest score is saved in a file named highscore.txt and loaded at the start of the game. 🏆📄💾
- 🎨 *Game Rendering:*
    - 🔳 The game grid and pieces are rendered using simple console characters.
    - 📊 The current score, high score, and drop speed are displayed after each update. 🎨📊🧱
- 🔄 *Pause and Restart:*
    - ⏯ The game can be paused or restarted at any time using the respective keys. 🔄⏸⚙
- 🎭 *Color-Coded Tetrominoes:*  
    - 🎨 Each tetromino has a unique color, making it easier to differentiate shapes on the grid. 🌈🔳
-  🛑 *Collision Detection:*  
    - 🚧 Prevents pieces from overlapping or moving outside the grid, ensuring a fair gameplay experience. 🚫🧱

## 📄 Files 🗂️💽
- `tetris.cpp` - 📄 The main C++ source code containing the game logic.
- `highscore.txt` - 🏆 A file that stores the highest score achieved.

## 🧠 Code Highlights 💡🔍
- 🔄 **Tetromino Management:**
    - 🟩 Each tetromino is represented as a 2D vector.
    - 🔄 Pieces can be rotated and moved within the grid. 🔄🟩⬛
- 🚫 **Collision Detection:**
    - ⚠️ Ensures that pieces don't overlap or go beyond the game boundaries. 🚫⚠️🧱
- 🗺️ **Game Grid:**
    - 📊 Maintained as a 2D vector representing the current state of the board. 🗺️📊🔢
- 🖥️ **Console Handling:**
    - ⚙️ The console cursor is managed for smooth rendering using Windows API functions. 🖥️🖱️⚙️

## ⚠️ Limitations ⛔🚧
- 🚫 Only works on Windows due to the usage of specific libraries.
- 🎨 Basic visual design due to console-based rendering.

## 🚀 Possible Enhancements 🔮💡
- 🌍 Cross-platform support by replacing Windows-specific code.
- 🎨 Adding colors for different tetrominoes using ANSI escape codes.
- 🖥 Implementing more advanced graphics using libraries like SDL or SFML.
- 🔊 Adding sound effects and background music.
-  Game Enhancements & Features
✅ Ghost Piece: Show a faint preview of where the current piece will land.
- ✅ Hold Piece Feature: Allow players to swap the current piece with a "held" piece.
- ✅ Next Piece Preview (Multiple Pieces):Show the next 3-5 upcoming tetrominoes instead of just one.

## 📜 License ⚖️🔓
MIT License

Copyright (c) 2025 RonakVataliya

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

## Contact 📧🌐🤝  
For any questions or contributions or found any bugs, feel free to reach out:

-> *Name: Vataliya Ronak*   
- *Email:* 202401241@daiict.ac.in  
- *GitHub:* https://github.com/RonakVataliya  

-> *Name: Tolani Dhaval*   
- *Email:* 202401228@daiict.ac.in  
- *GitHub:* https://github.com/Dhaval1306  

-> *Name: Taksh Chauhan*   
- *Email:* 202401223@daiict.ac.in  
- *GitHub:* https://github.com/Taksh-1105 

-> *Name: Vikas Soni*   
- *Email:* 202401214@daiict.ac.in  
- *GitHub:* https://github.com/Vikas-soni11  


---





