# 🐍 Snake & Duck 🦆 Game | COMSIL I - Final Project

**Student:** AT-- D-----N (2--1--1)  
**Course:** 소프트웨어개발도구및환경실습 I
**Date:** June 2025

## 🎮 About The Game

A classic snake game implemented in C++ for my final project.</br>
The head of the snake is duck 🦆. Because why not? </br>
The snake moves automatically and you control the direction. </br>
Eat apple 🍎 to grow and collect power-ups ⚡️ for bonus points!

## ✨ Features

- 🦆 **Duck emoji snake head** for fun and visibility
- 📏 **Large game board** (30x25) for better gameplay
- ⚡ **Power-up system** with bonus points (+25 each)
- 📈 **Level progression** every 50 points
- 🔄 **Replay functionality** after game over
- 🎯 **Fast-paced gameplay** with automatic movement

## 🎯 How to Play

- **W/A/S/D** - Change snake direction
- **X** - Quit game
- **Eat food (🍎)** - Grow snake and get 10 points
- **Collect power-ups (⚡️)** - Get 25 bonus points
- **Avoid walls and yourself!**

## 🛠️ How to Compile & Run

```bash
# Compile the game
g++ -std=c++11 -o snake_game src/snake_game.cpp

# Run the game
./snake_game
```

## 📁 Project Structure

```
├── src/
│   └── snake_game.cpp     # Main game source code
├── README.md              # This file
├── README.txt             # Original project documentation
├── Makefile              # Build configuration
├── compile_and_run.sh    # Quick compile script
└── .gitignore            # Git ignore rules
```

## 🎯 Game Elements

| Symbol | Description |
|--------|-------------|
| 🦆 | Snake head (duck) |
| o | Snake body |
| 🍎 | Food (+10 points) |
| ⚡️ | Power-up (+25 points) |
| . | Empty space |

## 🏆 Scoring System

- **Food:** +10 points per item
- **Power-up:** +25 bonus points per item  
- **Level up:** Every 50 points
- **Growth:** Snake grows by 1 segment per food

## 🖥️ System Requirements

- **OS:** macOS or Linux
- **Compiler:** g++ with C++11 support
- **Terminal:** Any standard terminal emulator

## 🎓 Learning Outcomes

This project demonstrates:
- Array usage for coordinate management
- Real-time input handling
- Game loop implementation
- Collision detection algorithms
- Function organization and modular programming
- Console-based user interface design

## 📸 Screenshots

```
+------------------------------+
|..............................|
|......🦆ooo...................|
|..............................|
|............🍎................|
|..............................|
|..................⚡️..........|
|..............................|
+------------------------------+

=== SNAKE & DUCK GAME ===
Score: 50 | Level: 2 | Length: 8
```

---

## Note from Dogukan 
I've created this game because I like ducks. </br>
Growing up the snake game was my favorite one on my mom's phone. </br>
I wanted my final project before my graduation to be something meaningful. </br>

Hope you enjoy playing it as well. It's just a simple game. Feel free to improve it. 
