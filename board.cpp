/* Sophie Pelton
  2370862
  spelton@chapman.edu
  CPSC350-01
  Assignemnt 3
    board.cpp
*/

#include "board.h"
#include <fstream>
#include <string>
#include <iostream>

/* class that has all the functions to change or get characters in the board
	creates a 2D array for the grid and can get all the neighbors of each point
*/

Board::Board(){} //default constructor

Board::Board(int row, int column){ //overloaded constructor
	m_rowNum = row;
	m_columnNum = column;

	m_curr = new char*[row];
    for (int i = 0; i < row; ++i){
       m_curr[i] = new char[column];
    }
}

Board::~Board(){ //default destructor
  for(int i = 0; i < m_rowNum; ++i){
    delete [] m_curr[i];
  }
  delete []m_curr;
}
//method to set any char at any point in the grid
void Board::setAt(int row, int column, char c){
  m_curr[row][column] = c;
}
//method to get any char at any point in the grid
char Board::getAt(int row, int column){
	// need to handle if row or column out of bounds via mode ...
	if(row > m_rowNum){
		cout << "get at bounds error" << endl;
	}
  return m_curr[row][column];
}
//method to get char directly above the given point in the grid
char Board::getAtNorth(int row, int column){
  return getAt(row-1, column);
}
//method to get char to the upper right diagonal the given point in the grid
char Board::getAtNorthEast(int row, int column){
  return getAt(row-1, column+1);
}
//method to get char directly right the given point in the grid
char Board::getAtEast(int row, int column){
  return getAt(row, column+1);
}
//method to get char to the lower right diagonal the given point in the grid
char Board::getAtSouthEast(int row, int column){
  return getAt(row+1, column+1);
}
//method to get char directly below the given point in the grid
char Board::getAtSouth(int row, int column){
  return getAt(row+1, column);
}
//method to get char to the lower left diagonal the given point in the grid
char Board::getAtSouthWest(int row, int column){
  return getAt(row+1, column-1);
}
//method to get char directly left the given point in the grid
char Board::getAtWest(int row, int column){
  return getAt(row, column-1);
}
//method to get char to the upper left of the given point in the grid
char Board::getAtNorthWest(int row, int column){
  return getAt(row-1, column-1);
}
//copies one boards contents to another board
void Board::copyBoard(Board *b){
	for(int i = 0; i< m_rowNum ; ++i){
		    for(int j = 0; j< m_columnNum; ++j){
		      m_curr[i][j] = b->getAt(i, j);
		    }
		  }
}
//clears out the board
void Board::clear(){
  for(int i = 0; i< m_rowNum ; ++i){
    for(int j = 0; j< m_columnNum; ++j){
      m_curr[i][j] = '\0';
    }
  }
}
//checks to see if two boards are equal and returns true if they are
bool Board::compare(Board *b){
  for(int i = 0; i< m_rowNum ; ++i){
    for(int j = 0; j< m_columnNum; ++j){
      if(m_curr[i][j] != b->getAt(i,j)){
        return false;
      }
    }
  }
  return true;
}
//prints out the contents of the board to the console
void Board::print(){
  for(int i = 0; i< m_rowNum ; ++i){
    for(int j = 0; j< m_columnNum; ++j){
      cout << m_curr[i][j];
    }
    cout << endl;
  }
}
//prints out the contents of the baord to a file
void Board::printToFile(std::ofstream *pfile, int generation){
	//parameter 1 is ofstrem
	//append

	*pfile << "Generation: " << generation << endl;

  for(int i = 0; i< m_rowNum ; ++i){
    for(int j = 0; j< m_columnNum; ++j){
      *pfile << m_curr[i][j];
    }
    *pfile << endl;
  }
}
//checks to see if the board is empty
bool Board::isEmpty(){

	for(int i = 0; i< m_rowNum ; ++i){
	  for(int j = 0; j< m_columnNum; ++j){
	    if(m_curr[i][j] != '-'){
				return false;
			}
	  }
	}
	return true;
}
//gets the number of rows in the board
int Board::getRow(){
  return m_rowNum;
}
//gets the number of columns in the board
int Board::getColumn(){
  return m_columnNum;
}
