//Asher Shores
//November 8th, 2020
//CST-210
//This is my own work

using namespace std;
#include <iostream>
#include <ctime>
#include <string>

class board {

//private data includes hint pegs and the code array itself
private:
char w, x, y, z;
char cipher[4];
char tempArray[4];
char tempCipher[4];
bool toggleDuplicates = false;
char firstPos, secondPos, thirdPos, fourthPos;
int count;
int blackCounter; 
int whiteCounter;


public:

//------------------------------------//
//overloaded operator bs ahahaha
board() : count(10) {}

//overloads -- because I never use it
//changes the private int count to one less
//allows user to check in main what their number of guesses is left
void operator -- () {

  --count;
  
}

void display() {
  cout << count << endl;
}
//------------------------------------//


void boardBuilder(char firstPos, char secondPos, char thirdPos, char fourthPos) {
  this->firstPos = firstPos;
  this->secondPos = secondPos;
  this->thirdPos = thirdPos;
  this->fourthPos = fourthPos;

  //run function for determining what hints to give this round
  determineHints();

  //generates single board line for cleaner look
  genBoardLine();
  
  //displays all color-coded pegs as given by user
  //displays newly determined hint peg values
  cout << "| " << firstPos << " | " << secondPos 
  << " | " <<  thirdPos << " | " << fourthPos << " | ";
  cout << w << " | " << x << " | " << 
  y << " | " << z << " |" << endl;
  //closes this round's board
  genBoardLine();

  cout << endl << "White Pegs: " << whiteCounter;
  cout << endl << "Black Pegs: " << blackCounter;
  cout << endl;

  return;
};

//method for determining hints to help user
void determineHints() {

  //initally sets all pegs to default state and overwrites if necessary
  w = 'X';
  x = 'X';
  y = 'X';
  z = 'X';

  //counters for black and white pegs and 
  //black and white pegs
  blackCounter = 0;
  whiteCounter = 0;

  //puts user cipher guess into temp array
  tempArray[0] = firstPos;
  tempArray[1] = secondPos;
  tempArray[2] = thirdPos;
  tempArray[3] = fourthPos;

  //puts user cipher guess into temp array
  tempCipher[0] = cipher[0];
  tempCipher[1] = cipher[1];
  tempCipher[2] = cipher[2];
  tempCipher[3] = cipher[3];

  //Temp arrays are created so that I can overwrite the data
  //when calculating the black and white pegs

  //Most difficult part here
  //Have to make sure pegs are not counted twice when the code contains
  //more than one peg of the same color
  //check for if any correct colors out of place were found

  //nested for loop to determine both black and white pegs
  for (int i = 0; i < 4; i++){

    //count black pegs based on if the user input matches the code
    //at the exact same i position in the same sized arrays
    if (tempArray[i] == tempCipher[i]){
      blackCounter++;

      //once counted they are converted to nonsense so they cannot be
      //counted again by the white peg detector
      tempArray[i] = 'Q';
      tempCipher[i] = 'Z';
    } else {

      //loop for white pegs
      //checks if position is wrong but color is correct
      for (int m = 0; m < 4; m++){
        if (tempArray[i] == tempCipher[m] &&
            tempArray[m] != tempCipher[m]) {
              whiteCounter++;

      //once counted they are converted to nonsense so they cannot be
      //counted again by the white peg detector
              tempCipher[m] = 'Q';
              tempArray[i] = 'Z';
              break;
            }
      }

    }

  }


  //overwrites default pegs to white color for every true white peg calculated

  //white goes from right to left
  if (whiteCounter > 0) {
    z = 'W';
  }
  if (whiteCounter > 1) {
    y = 'W';
  }
  if (whiteCounter > 2) {
    x = 'W';
  }
  if (whiteCounter > 3) {
    w = 'W';
  } 



  //black pegs take priority over white pegs and a black can be true for
  //one while white is also true so printing over white is useful
  //set black peg hints
  //black goes from left to right
  if (blackCounter > 0){
    w = 'B';
  }
  if (blackCounter > 1){
    x = 'B';
  }
  if (blackCounter > 2){
    y = 'B';
  }
  if (blackCounter > 3){
    z = 'B';
  }

};
//end of determine hints method


//checkpoint
//method for checking win by if each position corresponds to the position in cipher
bool checkWin() {
  if (firstPos == cipher[0] && secondPos == cipher[1] && thirdPos == cipher[2] && fourthPos == cipher[3]){
    return true; }
  else {
    return false;
  }
}

//generic board line method discussed above
void genBoardLine() {
  cout << "|---------------|---------------|" << endl;
  return ;
}; 


//generates random numbers for the code using ctime
//each integer 1 - 6 corresponds to a possible color
void genCipher() {

  int num;
  srand(time(0));

  for (int i = 0; i < 4; i++) {

    num = rand() % 6 + 1;

      if (num == 1){
      cipher[i] = 'b';
    } else if (num == 2){
      cipher[i] = 'g';
    } else if (num == 3){
      cipher[i] = 'o';
    } else if (num == 4){
      cipher[i] = 'p';
    } else if (num == 5){
      cipher[i] = 'r';
    } else if (num == 6){
      cipher[i] = 'y';
    }
  }

  //DEBUG
  //Tool for seeing cipher at beginning
  cout << endl << "DEBUG" << endl;
  for (int i = 0; i < 4; i++){
  cout << cipher[i];
  }

return;
};


//method for revealing code for both win and lose conditions
//also resets the values of the hint pegs for replay since that
//cannot be done from main.cpp
//has no affect on win condition though
void revealCode(){
  
  cout << endl << "The code was..." << endl << endl;

  for (int i = 0; i < 4; i++){
    
    cout << (cipher[i]);

  }

  //sets up right side pegs in default state for next game
  //can only be done in this class so this made logical sense
  w = 'X';
  x = 'X';
  y = 'X';
  z = 'X';

  return;
}


//end of board class
};