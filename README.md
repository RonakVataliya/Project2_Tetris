# 🎮 Tetris Game in C++ 🧩🚀

## Student ID 🆔📚🎓  
- *Vataliya Ronak: 202401241*  
- *Tolani Dhaval: 202401228*
- *Taksh Chauhan: 202401223*
- *Vikas Soni: 202401214*

## Table of Contents 📑🔍🗂    
1. [Overview]  
2. [Requirements]
3. [How to Compile]  
4. [How to Run] 
5. [Game Controls]
6. [Features] 
7. [Files]  
8. [Code Highlights] 
9. [Limitations]
10. [Possible Enhancements] 
11. [License]
12. [Contact]


## 🎯 Overview ✨📝
This is a console-based implementation of the classic Tetris game written in C++. It features:

- Real-time gameplay with keyboard controls.
- Progressive speed increase as the game progresses.
- High score tracking saved to a file.

## 🖥️ Requirements 🔧⚡
- 🪟 Windows OS (due to usage of Windows-specific headers like `<windows.h>` and `_kbhit()` for keyboard input).
- 🛠️ A C++ compiler that supports C++11 or higher (e.g., MinGW, MSVC).

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

## 🌟 Features 🚀🎮
- ⚡ **Dynamic Speed Adjustment:**
    - 🚀 The drop speed of the tetrominoes increases by 10% after every 5 pieces placed, with a minimum speed cap of 50ms. ⚡⏱️📈
- 🏆 **High Score Tracking:**
    - 📄 The highest score is saved in a file named `highscore.txt` and loaded at the start of the game. 🏆📄💾
- 🎨 **Game Rendering:**
    - 🔳 The game grid and pieces are rendered using simple console characters.
    - 📊 The current score, high score, and drop speed are displayed after each update. 🎨📊🧱
- 🔄 **Pause and Restart:**
    - ⏯️ The game can be paused or restarted at any time using the respective keys. 🔄⏸️⚙️

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
- 🖥️ Implementing more advanced graphics using libraries like SDL or SFML.
- 🔊 Adding sound effects and background music.

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





