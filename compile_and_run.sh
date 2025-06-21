#!/bin/bash
# Compilation and Test Script for Dogukan's Snake Game
# Student: ATAR DOGUKAN (20201961)

echo "========================================="
echo "Compiling Dogukan's Snake Game..."
echo "========================================="

# Compile the game
g++ -std=c++11 -Wall -o snake_game src/snake_game.cpp

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "✅ Compilation successful!"
    echo "Game executable created: snake_game"
    echo ""
    echo "To run the game, use: ./snake_game"
    echo ""
    echo "Game features:"
    echo "- Snake head with emoji (🐍)"
    echo "- WASD controls"
    echo "- Power-ups for bonus points"
    echo "- Level progression"
    echo "- Personalized welcome message"
    echo ""
    echo "Ready for submission!"
else
    echo "❌ Compilation failed!"
    echo "Please check the source code for errors."
fi 