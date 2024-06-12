//Asher Shores
//November 8th, 2020
//CST-210
//This is my own work

#include <iostream>
#include <ctime>
#include <string>

class board {
private:
    char w, x, y, z;
    char cipher[4];
    char tempArray[4];
    char tempCipher[4];
    int count;
    int blackCounter; 
    int whiteCounter;

    void determineHints();
    void genBoardLine();

public:
    board() : count(10) {}

    void operator-- () {
        --count;
    }

    void display() const {
        std::cout << count << std::endl;
    }

    void boardBuilder(char firstPos, char secondPos, char thirdPos, char fourthPos);
    bool checkWin(char firstPos, char secondPos, char thirdPos, char fourthPos) const;
    void genCipher();
    void revealCode();
};

// Method implementations

void board::boardBuilder(char firstPos, char secondPos, char thirdPos, char fourthPos) {
    tempArray[0] = firstPos;
    tempArray[1] = secondPos;
    tempArray[2] = thirdPos;
    tempArray[3] = fourthPos;

    determineHints();

    genBoardLine();
    std::cout << "| " << firstPos << " | " << secondPos 
              << " | " << thirdPos << " | " << fourthPos << " | "
              << w << " | " << x << " | " << y << " | " << z << " |" << std::endl;
    genBoardLine();

    std::cout << "\nWhite Pegs: " << whiteCounter;
    std::cout << "\nBlack Pegs: " << blackCounter;
    std::cout << std::endl;
}

void board::determineHints() {
    w = x = y = z = 'X';
    blackCounter = whiteCounter = 0;

    for (int i = 0; i < 4; ++i) {
        tempCipher[i] = cipher[i];
        if (tempArray[i] == tempCipher[i]) {
            blackCounter++;
            tempArray[i] = 'Q';
            tempCipher[i] = 'Z';
        }
    }

    for (int i = 0; i < 4; ++i) {
        if (tempArray[i] != 'Q') {
            for (int j = 0; j < 4; ++j) {
                if (tempArray[i] == tempCipher[j]) {
                    whiteCounter++;
                    tempCipher[j] = 'Z';
                    break;
                }
            }
        }
    }

    w = blackCounter > 0 ? 'B' : (whiteCounter > 0 ? 'W' : 'X');
    x = blackCounter > 1 ? 'B' : (whiteCounter > 1 ? 'W' : 'X');
    y = blackCounter > 2 ? 'B' : (whiteCounter > 2 ? 'W' : 'X');
    z = blackCounter > 3 ? 'B' : (whiteCounter > 3 ? 'W' : 'X');
}

bool board::checkWin(char firstPos, char secondPos, char thirdPos, char fourthPos) const {
    return firstPos == cipher[0] && secondPos == cipher[1] && thirdPos == cipher[2] && fourthPos == cipher[3];
}

void board::genBoardLine() {
    std::cout << "|---------------|---------------|" << std::endl;
}

void board::genCipher() {
    srand(time(0));
    for (int i = 0; i < 4; ++i) {
        int num = rand() % 6 + 1;
        cipher[i] = num == 1 ? 'b' : num == 2 ? 'g' : num == 3 ? 'o' : num == 4 ? 'p' : num == 5 ? 'r' : 'y';
    }

    // DEBUG
    std::cout << "\nDEBUG\n";
    for (int i = 0; i < 4; ++i) {
        std::cout << cipher[i];
    }
    std::cout << std::endl;
}

void board::revealCode() {
    std::cout << "\nThe code was...\n\n";
    for (int i = 0; i < 4; ++i) {
        std::cout << cipher[i];
    }
    std::cout << std::endl;

    w = x = y = z = 'X';
}
