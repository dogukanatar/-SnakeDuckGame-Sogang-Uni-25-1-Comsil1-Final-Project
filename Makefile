# Makefile for Dogukan's Snake Game
# Final Project for Software Development Tools and Environment Practice
# Student: ATAR DOGUKAN (20201961)

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Target executable
TARGET = snake_game

# Source files
SRCDIR = src
SOURCES = $(SRCDIR)/snake_game.cpp

# Default target
all: $(TARGET)

# Compile the game
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)
	@echo "Snake game compiled successfully!"
	@echo "Run with: ./$(TARGET)"

# Clean compiled files
clean:
	rm -f $(TARGET)
	@echo "Cleaned up compiled files"

# Run the game
run: $(TARGET)
	./$(TARGET)

# Help
help:
	@echo "Available targets:"
	@echo "  all    - Compile the snake game"
	@echo "  clean  - Remove compiled files"
	@echo "  run    - Compile and run the game"
	@echo "  help   - Show this help message"

.PHONY: all clean run help 