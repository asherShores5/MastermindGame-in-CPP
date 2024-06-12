//Asher Shores
//November 8th, 2020
//CST-210
//This is my own work

#include <iostream>
#include "board.h"
using namespace std;

// Variables for passing user data to board.h to check cipher
char a, b, c, d;
bool winFlag = false;

void startUp();

// Driver code for the main game
int main() {
    cout << "\033[2J\033[0;0H";
    startUp();

    cout << endl << endl << "Welcome to MASTERMIND" << endl << "By: Asher Shores";

    // Set vars to default status, mainly for replay resetting
    a = 'O';
    b = 'O';
    c = 'O';
    d = 'O';

    // Generate board object from board.h file and board class
    board boardObject;

    // Generate cipher for this game
    boardObject.genCipher();
    cout << endl << endl << "Here is your game board" << endl << endl;

    // Create board type with char values to be used in the game
    // Initializes with 'O' to represent empty peg slots
    boardObject.boardBuilder(a, b, c, d);

    // Clear introductions and allow user to proceed when ready
    cout << endl << endl;
    (void)system("read -p 'Press Enter to continue...' var");
    cout << endl;

    // Main loop for actual gameplay
    for (int n = 1; n < 11; n++) {
        cout << "\nEnter a letter to guess: (R)ed, (O)range, (Y)ellow, (G)reen, (B)lue, (P)urple\n";
        cout << "Or type 'c' to check your number of guesses left\n\n";

        for (int i = 0; i < 4; i++) {
            char input;
            bool validInput = false;

            // Loop until a valid input is entered
            while (!validInput) {
                cin >> input;
                validInput = (input == 'r' || input == 'o' || input == 'y' || input == 'g' || input == 'b' || input == 'p' || input == 'c' || input == 'C');

                if (!validInput) {
                    cout << "Please enter a character respective of a color ONLY" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                } else if (input == 'c' || input == 'C') {
                    cout << "Your number of guesses left is ";
                    boardObject.display();
                    validInput = false; // Prompt user again for this position
                }
            }

            // Sets input to actual values for the board object as it runs
            if (i == 0) a = input;
            if (i == 1) b = input;
            if (i == 2) c = input;
            if (i == 3) d = input;

            if (i != 3 && input != 'c' && input != 'C') {
                cout << endl << "Thanks, please enter another character" << endl;
            }
            cin.clear();
            cin.ignore(10000, '\n');
        }

        cout << endl;
        (void)system("read -p 'Press Enter to continue...' var");
        cout << endl << endl;

        // Send user chosen values to be checked in board class
        boardObject.boardBuilder(a, b, c, d);

        cout << endl;

        // Check for win condition
        if (boardObject.checkWin(a, b, c, d)) {
            cout << "Congratulations! YOU WIN!" << endl;
            cout << "You successfully cracked the code!" << endl;
            boardObject.revealCode();
            cout << endl;
            winFlag = true;
            break;
        }

        // Decrement the guess count
        --boardObject;

        // Display remaining guesses
        cout << "You have ";
        boardObject.display();
        cout << " guesses remaining" << endl;
    }

    // Allows for user to input for a replay if lost
    if (!winFlag) {
        cout << "Sorry, that's the max number of guesses..." << endl << endl;
        cout << "YOU LOSE!" << endl << endl;
        boardObject.revealCode();
        cout << endl << endl << endl;
    }

    // Allow user to reset game and try again or quit the system entirely
    char again;
    cout << endl;
    (void)system("read -p 'Press Enter to continue...' var");
    cout << "\033[2J\033[0;0H";
    cout << "Play Again? (y/n)" << endl;

    bool validReplayInput = false;
    while (!validReplayInput) {
        cin >> again;
        validReplayInput = (again == 'y' || again == 'Y' || again == 'n' || again == 'N');

        if (!validReplayInput) {
            cout << "Please enter correct input (y/n)" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        } else if (again == 'y' || again == 'Y') {
            main();
        } else if (again == 'n' || again == 'N') {
            exit(0);
        }
    }

    // End of main method
}

void startUp() {
    cout << " __  __           _                      _           _ " << endl;
    cout << "|  \\/  | __ _ ___| |_ ___ _ __ _ __ ___ (_)_ __   __| |" << endl;
    cout << "| |\\/| |/ _` / __| __/ _ \\ '__| '_ ` _ \\| | '_ \\ / _` |" << endl;
    cout << "| |  | | (_| \\__ \\ ||  __/ |  | | | | | | | | | | (_| |" << endl;
    cout << "|_|  |_|\\__,_|___/\\__\\___|_|  |_| |_| |_|_|_| |_|\\__,_|" << endl;
    cout << "-------------------------------------------------------";
}
