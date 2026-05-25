# C Tic-Tac-Toe

Console-based Tic-Tac-Toe (Jogo da Velha) game for two players, written in C++ with colored console output.

## Features

- 3x3 grid displayed with numbered positions (1–9)
- Color-coded marks: X in blue, O in red
- Win detection (rows, columns, diagonals)
- Draw detection
- Play again prompt (y/n)
- Portuguese-language interface

## Tech Stack

- **C++**
- Windows Console API (`<windows.h>`) for colored output

## Setup (Windows only)

```bash
g++ JogoDaVelha.cpp -o JogoDaVelha.exe
./JogoDaVelha.exe
```

> Note: This project uses `<windows.h>` and `system("cls")`, so it only runs on Windows.
