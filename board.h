/* Sophie Pelton
  2370862
  spelton@chapman.edu
  CPSC350-01
  Assignemnt 3
    board.h
*/

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <exception>
#include <string>
#include <stdio.h>
#include <fstream>
#include <iostream>

using namespace std;

class Board{
  public:
    Board(); //default constructor
    ~Board(); //default destructor
    Board(int row, int column); //overloaded constructor

    void setAt(int row, int column, char c);
    //sets char at a coordinate
    char getAt(int row, int column);
      //this handles the get value at a coordinate, but also handles if the x,y
      //are out of bounds based on the mode
    char getAtNorth(int row, int column);
      /*function that gets the value of the north neighbor – specialized version of getAt() and should just calculate the x,y coordinate of the North neighbor
      */
    char getAtSouth(int row, int column);
    //function to get the neighbor below the given point
    char getAtWest(int row, int column);
    //method to get the neighbor to the left of the given point
    char getAtEast(int row, int column);
    //method to get the neighbor to theright of the given point
    char getAtNorthWest(int row, int column);
    //method to get the neighbor to the top left of the give point
    char getAtNorthEast(int row, int column);
    //method to get the neighbor to the top right of the give point
    char getAtSouthWest(int row, int column);
    //method to get the neighbor to the bottom left of the give point
    char getAtSouthEast(int row, int column);
    //method to get the neighbor to the bottom right of the give point

    int getRow(); //gets the number of rows in a grid
    int getColumn(); //gets the number of columns in a grid

    void clear(); // clears THIS board instance
    void copyBoard(Board *b); //  copies from the source board to THIS instance of the board
    bool isEmpty(); //checks is the boards characters are all '-'

    bool compare(Board *b);  // compares a board with THIS instance of the board;
    void print();  // print the board
    void printToFile(std::ofstream *pfile, int generation); //prints the boards contents to a file using the ofstrem and also prints the generation number

  private:
    int m_rowNum; //number of rows
    int m_columnNum; //number of columns

    char **m_curr; //2D array to represent the grid
};

#endif
