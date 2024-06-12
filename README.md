# Project - Mastermind Game in C++

This project recreates the classic game of Mastermind using the C++ programming language.

## Simple Run

Visit this [Replit Page](https://replit.com/@AsherShores1/MasterMind) and fork the code to run it using Replit's C++ console if you are unable to download and run it in your own compiler.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

1. You will need to have a C++ compiler installed on your machine. 

### Installing

1. Clone or download the repository onto your local machine.

   ```bash
   git clone https://github.com/your-username/mastermind-game-demo.git
   cd mastermind-game-demo
   ```

3. Open the terminal and navigate to the project directory.

4. Compile the source code using the following command:
   ```bash
   g++ -o mastermind mastermind.cpp
   ```

6. Run the program using the following command:
   ```
   ./mastermind
   ```

## Playing the Game

1. The program will display the game board and prompt you to enter your guesses.

2. You will make guesses by entering a sequence of characters representing colors:

   - Red (R)
   - Orange (O)
   - Yellow (Y)
   - Green (G)
   - Blue (B)
   - Purple (P)

3. After each guess, the program will give you feedback:

- Black peg (B): A correct color in the correct position.
- White peg (W): A correct color in the wrong position.

4. Keep making guesses until you either crack the code or reach the maximum number of attempts.

## Built With

- C++ programming language

## Author

- Asher Shores, 2020

## License
This project is licensed under the MIT License - see the [LICENSE](https://github.com/asherShores5/MastermindGame-in-CPP/blob/main/LICENSE) file for details.
