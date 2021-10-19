/* Sophie Pelton
  2370862
  spelton@chapman.edu
  CPSC350-01
  Assignemnt 3
    main.cpp
*/

/* in the main, we get user input and use it to run the game of Life
  called functions from mode, game, MapProcess, and board class
*/
#include <iostream>
#include "game.h"
#include "mode.h"
#include "mapProcess.h"
#include <unistd.h>

using namespace std;

int main(int argc, const char * argv[]) {
  //current board
  Board *b;
  //next generation board
  Board *next;
  //previous generation board
  Board *prev;
  //game object to run game
  game *g = new game();
  //MapProcess object for creating the grid
  MapProcess *mp = new MapProcess();

  char userChoice; //choice for how map is created
  char modeChoice; //choice for which mode they want to play in
  char betweenChoice; // choice for how to see each generation
  bool run = true; //for while loop to get correct user input
  bool gameRun = true; //for while loop for playing the game
  unsigned int numRow = 0; //number of rows in the board
  unsigned int numColumns = 0; //number of columns in the baord
  double popDensity = 0.0; //population density from user input
  string fileName; //input file name to read grid from
  string outputFile; //output file to write each generation to
  std::ofstream fileOut; //ofstream for writing to the output file
  string str; //string for user input during game running loop

  cout << "Welcome to the Game of Life" << endl;
  cout << "Would you like to provide a map file or do random assignment (M/R): " << endl;
  cin >> userChoice;
  //user input for making the map randomly or from input file

  while(run){

    if(userChoice == 'R'){ //creates random board
      cout << "You choose Random Assignment" << endl;
      cout << "enter the number of rows: " << endl;
      cin >> numRow;
      cout << "enter the number of columns: " << endl;
      cin >> numColumns;
      cout << "enter the population density (0.0-1.0): " << endl;
      cin >> popDensity;

      if(popDensity > 1.0){
        cout << "try again! enter the population density" << endl;
        cin >> popDensity;
      }else if (popDensity < 0.0){
        cout << "try again! enter the population density" << endl;
        cin >> popDensity;
      }

      cout << "generating map..." << endl;
      //call map process
      b = new Board(numRow, numColumns); //creates board with user specified number of rows and columns
      b = mp->makeMap(numRow, numColumns, popDensity); //creates a random map
      next = new Board(numRow, numColumns); //creates board with user specified number of rows and columns
      next->copyBoard(b); //copies board for next generation
      prev = new Board(b->getRow(), b->getColumn()); //creates board with user specified number of rows and columns
      prev->copyBoard(b); //copies board for previous generation
      cout << "Generation: 1" << endl;
      b->print(); //prints out board for user
      //now false so the loop stops -- board has been created
      run = false;

    }else if (userChoice == 'M'){
      cout << "You choose Map File" << endl;
      cout << "Enter the file name: " << endl;
      cin >> fileName;

  //read file with MapProcess
      b = new Board();
      b = mp->readFile(fileName);
      b->print();
      next = new Board(b->getRow(), b->getColumn()); //creates board with user specified number of rows and columns
      next->copyBoard(b); //copies board for next generation
      prev = new Board(b->getRow(), b->getColumn()); //creates board with user specified number of rows and columns
      prev->copyBoard(b); //copies board for previous generation
      run = false; //now false so the loop stops -- board has been created
    }else {
        //incorrect input
      cout << "You entered the wrong character. try again" << endl;
      cin >> userChoice;
      //user input error
    }
  }

    //check for boundarymode
  modeChoice = ' ';
  while ((modeChoice != 'C') && (modeChoice != 'M') &&  (modeChoice != 'D') ) {
    cout << "Which Boundary mode do you want to use? Classic(C), Mirror(M), or Donut(D)" << endl;
    cin >> modeChoice;

    if ((modeChoice != 'C') && (modeChoice != 'M') &&  (modeChoice != 'D') ){
      cout << "You entered the wrong character. try again" << endl;
    }
  }
    //ask if they want a...
      //brief pause between generations (system::pause)
      //want to have to press enter key to display next generation (print to console)
      //want to output everything to a file
        //prompt for an output file

  betweenChoice = ' ';
  while ((betweenChoice != 'P') && (betweenChoice != 'E') &&  (betweenChoice != 'O') ) {
    cout << "Between each generation would you like a brief pause (P)" << endl;
    cout << "OR would you like to press the enter key to display the next generation (E)" << endl;
    cout << "OR would you like to write out all generations to an output file (O)" << endl;
    cin >> betweenChoice;
    getline(cin, str);

    if ((betweenChoice != 'P') && (betweenChoice != 'E') &&  (betweenChoice != 'O') ){
      cout << "You entered the wrong character. try again" << endl;
      cin >> betweenChoice;
      getline(cin, str);
    }
  }

  if(betweenChoice == 'O'){
    cout << "Please enter an output file name" << endl;
    cin >> outputFile;

    fileOut.open(outputFile, ios::out | ios::trunc);
    // checks if there is a fail opening the file
    if(fileOut.fail()){
      cout << "Bad file input" << endl;
      exit(-1);
    }
    b->printToFile(&fileOut, 1);
  }


    //run Game
      //if infinite keep running (while loop)
      //if oscillating tell them to press enter to exit
      //if empty then stop and ask the user to press enter to exit (call from board, break from loop)

  int generation = 1;
  int counter = 0;
  while(gameRun){

    g->play(b, next, modeChoice); // play one round

    if(generation > 1 && (counter == 2)){
      prev->copyBoard(b);
    }
      //checks if board is empty
    if(b->isEmpty()){
      cout << "The board is empty. Please press enter." << endl;
      if(betweenChoice == 'P' || betweenChoice == 'O'){
        cin.ignore();
      }
      getline(cin, str);
      if(str == ""){
        gameRun = false;
        return 0;
      } else {
        cout << "Oops. Try pressing enter instead." << endl;
        getline(cin, str);
      }
    } //checks if the boards are the same
    else if ((generation > 1) && (b->compare(next) == true)) {
      cout << "The generations current and next generation are the same. Please press enter." << endl;
      if(betweenChoice == 'P' || betweenChoice == 'O'){
        cin.ignore();
      }
      getline(cin, str);
      if(str == ""){
        gameRun = false;
        return 0;
      } else {
        cout << "Oops. Try pressing enter instead." << endl;
        getline(cin, str);
      }
    } //checks if board is oscilating
    else if( (generation > 1) && prev->compare(next) == true){
      cout << "The generations are oscilating. Press enter to exit.";
      if(betweenChoice == 'P' || betweenChoice == 'O'){
        cin.ignore();
      }
      getline(cin, str);
      if(str == ""){
        gameRun = false;
        return 0;
      } else {
        cout << "Oops. Try pressing enter instead." << endl;
        getline(cin, str);
      }
    }
      //increments generation
    generation++;
      //increment counter for changing the previous generation board
    ++counter;
      //copied contents of next generation to current board b
    b->copyBoard(next);
      //prints out generation and board for user to console
    cout << "Generation: " << generation << endl;
    b->print();

    if(betweenChoice == 'P'){
      //pauses the program for 2 seconds between generation
      //cin.ignore();
      sleep(2);
    }else if(betweenChoice == 'E'){
      //want to have to press enter key to display next generation (print to console)
      cout << "Press enter to continue:" << endl;
      getline(cin, str);
      if(str == ""){
        continue;
      }
    }else if(betweenChoice == 'O'){
      //prints contents to the output file
      b->printToFile(&fileOut, generation);
    }
  }

  delete mp;
  delete b;
  delete next;
  delete g;
  return 0;
}
