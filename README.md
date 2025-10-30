# 🎮 Tic Tac Toe Game in C

A classic **Tic Tac Toe** game built from scratch in C, featuring clean code architecture, robust input validation, and intelligent win/draw detection.

## ✨ Features

- ✅ **Two-player gameplay** - Player 1 (X) vs Player 2 (O)
- ✅ **Smart win detection** - Detects all winning combinations (rows, columns, diagonals)
- ✅ **Draw detection** - Automatically identifies stalemate situations
- ✅ **Input validation** - Handles invalid moves and non-numeric input gracefully
- ✅ **Clean code design** - Modular functions with clear documentation
- ✅ **Console-based UI** - Clear board display with visual grid

## 🚀 How to Run

### On Windows

#### Using Code::Blocks or Dev-C++
1. Open the IDE
2. Load `tic_tac_toe.c`
3. Press `F9` (Code::Blocks) or `F11` (Dev-C++) to compile and run

#### Using Command Line
```bash
# Compile
gcc tic_tac_toe.c -o tic_tac_toe.exe

# Run
tic_tac_toe.exe
```

#### Using Batch File
Simply double-click `compile_and_run.bat`

### On Linux/Mac
```bash
# Compile
gcc tic_tac_toe.c -o tic_tac_toe

# Run
./tic_tac_toe
```

## 🎯 How to Play

1. Players take turns entering their moves
2. Enter **row number** (0-2) when prompted
3. Enter **column number** (0-2) when prompted
4. First player to get 3 in a row wins!
5. If the board fills with no winner, it's a draw

### Board Layout
```
   0   1   2
0  [ ] [ ] [ ]
1  [ ] [ ] [ ]
2  [ ] [ ] [ ]
```

## 📋 Requirements

- C Compiler (GCC, MinGW, or any standard C compiler)
- No external libraries required
- Compatible with C99 and later standards

## 🛠️ Code Structure

```c
displayBoard()   // Displays the current game board
checkWin()       // Detects winning combinations
checkDraw()      // Checks for draw conditions
makeMove()       // Places player's mark on board
isValidMove()    // Validates move coordinates
```

## 🎓 Learning Highlights

This project demonstrates:
- 2D array manipulation
- Function modularization
- Input validation and error handling
- Game state management
- Loop control structures

## 📝 License

Free to use for educational purposes.

## 👨‍💻 Author

Built with ❤️ as a C programming practice project

---

**⭐ If you found this helpful, please star this repository!**
