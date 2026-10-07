# Rock Paper Scissors (C++)

A console-based Rock Paper Scissors game written in C++, where you play against the computer.

notepad README.md

## Features

- Play against the computer, which picks its move randomly
- Choose how many rounds to play (1 to 10)
- Input validation: the game keeps asking until you enter a valid choice
- The screen color changes after every round:
  - Green when you win
  - Red (with a beep) when the computer wins
  - Yellow when the round is a draw
- Final results screen showing rounds played, your wins, computer wins, draws, and the final winner
- Option to play again without restarting the program

## How to Play

1. Enter the number of rounds (1 to 10)
2. In each round, choose: `1` for Stone, `2` for Paper, `3` for Scissors
3. After the last round, the game shows the final results
4. Press `Y` to play again or `N` to exit

## How to Run

1. Clone the repository:
```
   git clone https://github.com/hxl7p/rock-paper-scissors-cpp.git
```
2. Open `Project_After.sln` in Visual Studio
3. Press `Ctrl + F5` to build and run

This project runs on Windows, because it uses Windows console commands for colors and clearing the screen.

## What I Practiced

- Enums and structs to organize game data
- Splitting the program into small functions
- Random number generation
- Loops and input validation

## Author

Ahmad Afara