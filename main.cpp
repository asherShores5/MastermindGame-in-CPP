//Asher Shores
//November 8th, 2020
//CST-210
//This is my own work

#include <iostream>
#include "board.h"
using namespace std;

//variables for passing user data to board.h to check cipher
//using "cipher" rather than "code" because that's less confusing
char a;
char b;
char c;
char d;

bool winFlag = false;


void startUp();

//Driver code for main game 
//Can be called recursively in the event of 
//game loss/win for infinite replays
int main() {
  cout << "\033[2J\033[0;0H";

  startUp();

  //game introductions
  cout << endl << endl << "Welcome to MASTERMIND" << endl << "By: Asher Shores";

  //set vars to default status, mainly for replay resetting
  a = 'O';
  b = 'O';
  c = 'O';
  d = 'O';


  //generate board object from board.h file and board class
  board boardObject;

  //generate cipher for this game
  boardObject.genCipher();
  cout << endl << endl << "Here is your game board" << endl << endl;

  //create board type with char values to be used in game
  //initializes with 'O' to represent empty peg slots
 boardObject.boardBuilder(a, b, c, d);

  
  //Clear introductions and allow user to proceed when ready
  cout << endl << endl;
  system("read -p 'Press Enter to continue...' var");
  cout << endl;
  //cout << "\033[2J\033[0;0H";



//Mega loop for actual game play
//--------------------------------------------------------//
//--------------------------------------------------------//
for (int n = 1; n < 11; n++){

  //Explains how user can input their guesses for game
  cout << "\nEnter a letter to guess: (R)ed, (O)range, (Y)ellow, (G)reen, (B)lue, (P)urple\n";
  cout << "Or type 'c' to check your number of guesses left\n\n";

char input;
bool inputFlag = true;


//for loop for each of four inputs for cipher
for (int i = 0; i < 4; i++){
//do loop to run forever until valid input
do {
  cin >> input;
  //assume that input is valid
  inputFlag = true;

  //checks if input has char that coordinates to a color
  if (input == 'r' || input == 'o' || input == 'y' 
  ||  input == 'g' || input == 'b' || input == 'p'
  ||  input == 'c' || input == 'C'){
    break;
  }

  //passive agressive message for people who break the rules
  cout << "Please enter a character respective of a color ONLY" << endl;
  cin.clear();
  cin.ignore(10000, '\n');

  //no true end condition as inputFlag is always true
  //only way to end is to activate if statement and break;
  } while (inputFlag == true);

  if (input == 'c' || input == 'C'){
   cout << "Your number of guesses left is ";
    boardObject.display();
    i = i - 1;
    cout << "\nEnter a letter to guess: (R)ed, (O)range, (Y)ellow, (G)reen, (B)lue, (P)urple\n";
      cout << "Or type 'c' to check your number of guesses left\n\n";
    continue;
  }

//if for reminding user to continue to enter until four inputs
if (i != 3){
cout << endl << "Thanks, please enter another character" << endl;
}
cin.clear();
cin.ignore(10000, '\n');

//sets input to actual values for the board object as it runs
if (i == 0){
  a = input;
}if (i == 1){
  b = input;
}if (i == 2){
  c = input;
}if (i == 3){
  d = input;
}

}

  //allows user to proceed when ready and clears board of this round's choices
  cout << endl;
  system("read -p 'Press Enter to continue...' var");
  cout << endl << endl;
  //cout << "\033[2J\033[0;0H";

  //sends user chosen values to be checked in board class
  boardObject.boardBuilder(a, b, c, d);

  cout << endl;

  //after generated board, checks for win condition
  //if win, code displayed and system exited
  if (boardObject.checkWin() == true){
    cout << "Congratulations! YOU WIN!" << endl;
    cout << "You successfully cracked the code!" << endl;
    boardObject.revealCode();
    cout << endl;
    winFlag = true;
    break;
  }

  //uses the overloaded operator
  --boardObject;


  //uses display function for overloaded oeprator to 
  //show remaining guesses
  cout << "You have ";
  boardObject.display();
  cout << "Guesses remaining" << endl;

}
//-----------------------------------------------------//
//-----------------------------------------------------//

//allows for user to input for a replay if lost
char again;

if (winFlag == false) {//---------
//Output for game loss case
cout << "Sorry thats the max number of guesses..." << endl << endl;
cout << "YOU LOSE!" <<endl<<endl;

//reveals code through method in board class
//cannot access cipher[] directly as it is a private array of chars
boardObject.revealCode();
cout << endl << endl << endl;
}//---------

//allows user to reset game and try again or quit the sytem entirely
cout << endl;
system("read -p 'Press Enter to continue...' var");
cout << "\033[2J\033[0;0H";
cout << "Play Again? (y/n)" << endl;

//copied over from above, doesn't allow any user funny-business for
//user input, only allows char y or n
bool inputFlagEnd = true;
do {
  cin >> again;
  //assume that input is valid
  inputFlagEnd = true;

  //checks if input has char that coordinates to a color
  if (again == 'y' || again == 'Y' 
  || again == 'n' || again == 'N')
  {
    if (again == 'y' || again == 'Y'){
  main();
  } else if (again == 'n' || again == 'N') {
  exit(0);
  }

  }

  //passive agressive message for people who break the rules
  cout << "Please enter correct input (y/n)" << endl;
  cin.clear();
  cin.ignore(10000, '\n');

  //no true end condition as inputFlag is always true
  //only way to end is to activate if statement and break;
  } while (inputFlagEnd == true);





//end of main method
}


void startUp() {
  cout << " __  __           _                      _           _ " << endl;
  cout << "|  \\/  | __ _ ___| |_ ___ _ __ _ __ ___ (_)_ __   __| |"<< endl;
  cout << "| |\\/| |/ _` / __| __/ _ \\ '__| '_ ` _ \\| | '_ \\ / _` |"<< endl;
  cout << "| |  | | (_| \\__ \\ ||  __/ |  | | | | | | | | | | (_| |"<< endl;
  cout << "|_|  |_|\\__,_|___/\\__\\___|_|  |_| |_| |_|_|_| |_|\\__,_|"<< endl;
  cout << "-------------------------------------------------------";

}