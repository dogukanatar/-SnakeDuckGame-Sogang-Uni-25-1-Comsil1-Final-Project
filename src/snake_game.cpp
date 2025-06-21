/*
 * Snake Game - Final Project
 * Student: ATAR DOGUKAN (20201961)
 * Course: Software Development Tools and Environment Practice
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <string>

using namespace std;

const int WIDTH = 30;
const int HEIGHT = 25;
const int MAX_LENGTH = 200;

int snakeX[MAX_LENGTH], snakeY[MAX_LENGTH];
int length, foodX, foodY, score, level;
char dir;
bool gameOver;
bool powerUpActive;
int powerUpX, powerUpY, powerUpTimer;

void setup();
void draw();
void input();
void logic();
void generateFood();
void generatePowerUp();
void gameOverScreen();
int kbhit();
char getch();

int main() {
    cout << "Welcome to Dogukan's Snake Game!" << endl;
    cout << "Controls: W(up) A(left) S(down) D(right)" << endl;
    cout << "Press Enter to start..." << endl;
    cin.get();
    
    bool playAgain = true;
    
    while (playAgain) {
        setup();
        
        while (!gameOver) {
            draw();
            input();
            logic();
            usleep(150000);
        }
        
        gameOverScreen();
        
        char choice = ' ';
        bool validChoice = false;
        
        while (!validChoice) {
            cout << "\n========================================" << endl;
            cout << "What would you like to do?" << endl;
            cout << "R or r - Play Again" << endl;
            cout << "Q or q - Quit Game" << endl;
            cout << "========================================" << endl;
            cout << "Enter your choice: ";
            
            string input;
            getline(cin, input);
            
            if (!input.empty()) {
                choice = input[0];
            } else {
                choice = ' ';
            }
            
            cout << "You entered: '" << choice << "'" << endl;
            
            if (choice == 'r' || choice == 'R') {
                playAgain = true;
                validChoice = true;
                cout << "\n>> Starting new game..." << endl;
                cout << "Get ready..." << endl;
                usleep(1500000);
            } else if (choice == 'q' || choice == 'Q') {
                playAgain = false;
                validChoice = true;
                cout << "\n>> Thanks for playing Dogukan's Snake Game!" << endl;
                cout << "Goodbye!" << endl;
            } else {
                cout << "\n!! Invalid choice! You entered '" << choice << "'" << endl;
                cout << "Please enter only R, r, Q, or q." << endl;
                cout << "Try again..." << endl;
            }
        }
    }
    
    return 0;
}

void setup() {
    gameOver = false;
    dir = 'd';
    length = 3;
    score = 0;
    level = 1;
    powerUpActive = false;
    powerUpTimer = 0;
    
    snakeX[0] = WIDTH / 2;
    snakeY[0] = HEIGHT / 2;
    for (int i = 1; i < length; i++) {
        snakeX[i] = snakeX[0] - i;
        snakeY[i] = snakeY[0];
    }
    
    generateFood();
    srand(time(0));
    generatePowerUp();
}

void draw() {
    char gameBoard[HEIGHT][WIDTH];
    
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            gameBoard[i][j] = '.';
        }
    }
    
    for (int k = 1; k < length; k++) {
        if (snakeX[k] >= 0 && snakeX[k] < WIDTH && snakeY[k] >= 0 && snakeY[k] < HEIGHT) {
            gameBoard[snakeY[k]][snakeX[k]] = 'o';
        }
    }
    
    if (foodX >= 0 && foodX < WIDTH && foodY >= 0 && foodY < HEIGHT) {
        gameBoard[foodY][foodX] = '*';
    }
    
    if (powerUpActive && powerUpX >= 0 && powerUpX < WIDTH && powerUpY >= 0 && powerUpY < HEIGHT) {
        gameBoard[powerUpY][powerUpX] = '+';
    }
    
    system("clear");
    
    cout << "+";
    for (int i = 0; i < WIDTH; i++) {
        cout << "-";
    }
    cout << "+" << endl;
    
    for (int i = 0; i < HEIGHT; i++) {
        cout << "|";
        for (int j = 0; j < WIDTH; j++) {
            if (i == snakeY[0] && j == snakeX[0]) {
                cout << "🦆";
            } else {
                cout << gameBoard[i][j];
            }
        }
        cout << "|" << endl;
    }
    
    cout << "+";
    for (int i = 0; i < WIDTH; i++) {
        cout << "-";
    }
    cout << "+" << endl;
    
    cout << endl;
    cout << "=== DOGUKAN'S SNAKE GAME ===" << endl;
    cout << "Score: " << score << " | Level: " << level << " | Length: " << length << endl;
    cout << "Duck = Snake Head | o = Body | . = Empty | * = Food | + = Power-up" << endl;
    if (powerUpActive) {
        cout << ">> POWER-UP AVAILABLE! Collect '+' for +25 bonus points!" << endl;
    }
    cout << "Controls: W(up) A(left) S(down) D(right) | X(quit)" << endl;
}

void input() {
    if (kbhit()) {
        char key = getch();
        switch (key) {
            case 'w':
            case 'W':
                if (dir != 's') dir = 'w';
                break;
            case 'a':
            case 'A':
                if (dir != 'd') dir = 'a';
                break;
            case 's':
            case 'S':
                if (dir != 'w') dir = 's';
                break;
            case 'd':
            case 'D':
                if (dir != 'a') dir = 'd';
                break;
            case 'x':
            case 'X':
                gameOver = true;
                break;
        }
    }
}

void logic() {
    int prevX = snakeX[0];
    int prevY = snakeY[0];
    int prev2X, prev2Y;
    
    switch (dir) {
        case 'w': snakeY[0]--; break;
        case 's': snakeY[0]++; break;
        case 'a': snakeX[0]--; break;
        case 'd': snakeX[0]++; break;
    }
    
    if (snakeX[0] < 0 || snakeX[0] >= WIDTH || snakeY[0] < 0 || snakeY[0] >= HEIGHT) {
        gameOver = true;
        return;
    }
    
    for (int i = 1; i < length; i++) {
        if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i]) {
            gameOver = true;
            return;
        }
    }
    
    for (int i = 1; i < length; i++) {
        prev2X = snakeX[i];
        prev2Y = snakeY[i];
        snakeX[i] = prevX;
        snakeY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    
    if (snakeX[0] == foodX && snakeY[0] == foodY) {
        score += 10;
        length++;
        generateFood();
        
        if (score % 50 == 0) {
            level++;
        }
        
        if (rand() % 2 == 0) {
            generatePowerUp();
        }
    }
    
    if (powerUpActive && snakeX[0] == powerUpX && snakeY[0] == powerUpY) {
        score += 25;
        powerUpActive = false;
        powerUpTimer = 0;
    }
    
    if (powerUpActive) {
        powerUpTimer++;
        if (powerUpTimer > 20) {
            powerUpActive = false;
            powerUpTimer = 0;
        }
    }
}

void gameOverScreen() {
    system("clear");
    
    cout << "========================================" << endl;
    cout << "           GAME OVER!" << endl;
    cout << "========================================" << endl;
    cout << "Final Score: " << score << endl;
    cout << "Level Reached: " << level << endl;
    cout << "Snake Length: " << length << endl;
    cout << "========================================" << endl;
    
    if (score >= 100) {
        cout << "Excellent performance! You're a snake master!" << endl;
    } else if (score >= 50) {
        cout << "Good job! Keep practicing to get even better!" << endl;
    } else {
        cout << "Nice try! Practice makes perfect!" << endl;
    }
    cout << "========================================" << endl;
}

void generateFood() {
    bool validPosition = false;
    
    while (!validPosition) {
        foodX = rand() % WIDTH;
        foodY = rand() % HEIGHT;
        
        validPosition = true;
        
        for (int i = 0; i < length; i++) {
            if (foodX == snakeX[i] && foodY == snakeY[i]) {
                validPosition = false;
                break;
            }
        }
        
        if (powerUpActive && foodX == powerUpX && foodY == powerUpY) {
            validPosition = false;
        }
    }
}

void generatePowerUp() {
    if (powerUpActive) return;
    
    bool validPosition = false;
    
    while (!validPosition) {
        powerUpX = rand() % WIDTH;
        powerUpY = rand() % HEIGHT;
        
        validPosition = true;
        
        for (int i = 0; i < length; i++) {
            if (powerUpX == snakeX[i] && powerUpY == snakeY[i]) {
                validPosition = false;
                break;
            }
        }
        
        if (powerUpX == foodX && powerUpY == foodY) {
            validPosition = false;
        }
    }
    
    powerUpActive = true;
    powerUpTimer = 0;
}

int kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;
    
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    
    ch = getchar();
    
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    
    if(ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }
    
    return 0;
}

char getch() {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
} 