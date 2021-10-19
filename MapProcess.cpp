/* Sophie Pelton
  2370862
  spelton@chapman.edu
  CPSC350-01
  Assignemnt 3
    MapProcess.cpp
*/

#include "MapProcess.h"
#include "board.h"

/*this class makes the boards from either random assignment or from an input file and returns the board
*/

MapProcess::MapProcess(){ //default constructor
}

MapProcess::~MapProcess(){ //default destructor
}

Board *MapProcess::readFile(string input){
  //creates an input stream to read from a file
  std::ifstream myfileIN;

  //string where the line from the file is put
  std::string line;
  std::istringstream iss; // string stream used for parsing line

  int numRow;
  int numColumns;
  Board *b;

  //opens the input file for reading
  myfileIN.open(input, ios::in);
  // checks if there is a fail opening the file --> bad input
  if(myfileIN.fail()){
    cout << "bad file input" << endl;
    exit(-1);
  }

  //checks if the input and output file is open
  if (myfileIN.is_open()){
	  // get number of rows
	  std::getline(myfileIN, line, '\n');
	  iss.str(line);
	  if (!(iss >> numRow)) {
      cout<< "expected number of rows" << endl; return (Board *)nullptr;
    }

	  // get number of columns
	  std::getline(myfileIN, line, '\n');
	  std::istringstream iss(line);
	  if (!(iss >> numColumns)) {
      cout << "expected number of columns" << endl; return (Board *)nullptr;
    }
      // construct new board
    b = new Board(numRow, numColumns);

      // Begin reading your stream here
      //for loop to go through each line of the file

    for(int i = 0; i < numRow ; ++i){
    std::getline(myfileIN, line, '\n'); // this line contains all the char in a row
      for(int j = 0; j< numColumns; ++j){
        b->setAt(i,j, line[j]);
      }
    }

      //closes  files after done using them
    myfileIN.close();
  } else {
    cout << "Problem opening file" << endl;
    exit(-1);
  }

  return b;
}

Board *MapProcess::makeMap(int row, int col, double density){
  srand(time(NULL)); //makes sure it is a new random generator each time

  Board *b = new Board(row, col);
  //creates a new board with the number of rows and columns passed in
  double pop = ((double)row*(double)col*density); //calculates the population of the grid
  int population = (int)pop; //casts the population to a n int
  int randomRow;
  int randomColumn;
  //for loop to set each element in the grid to '-'
  for (int ii=0; ii< row; ii++){
    for (int jj=0; jj< col; jj++){
      b->setAt(ii, jj, '-');
    }
  }
  //for loop to set random grid points with population density
  for(int i=0 ; i < population; ++i){
    randomRow = rand() % row;
    randomColumn = rand() % col;
    if(b->getAt(randomRow, randomColumn) == '-'){
      b->setAt(randomRow, randomColumn, 'X');
    }else{
      --i;
    }
  }
  //returns a randomly generated baord
  return b;
}
