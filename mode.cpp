/* Sophie Pelton
  2370862
  spelton@chapman.edu
  CPSC350-01
  Assignemnt 3
    mode.cpp
*/

//checks for the number of neighbors depending on the specified mode and the location of the coordinate in the grid
//rules for each mode

#include "mode.h"

mode::mode(){ //default constructor
}

mode::~mode(){ //default destructor
}
//method to check the rules of classic mode
int mode::checkClassic(int row, int column, Board *b){
  char currChar1;
  char currChar2;
  char currChar3;
  char currChar4;
  char currChar5;
  char currChar6;
  char currChar7;
  char currChar8;
  int sum = 0;
  if(row == 0 && column == 0){
    //top left corner case
    //gets the character from all its neighbors
    currChar1 = b->getAtSouth(row, column);
    currChar2 = b->getAtEast(row, column);
    currChar3 = b->getAtSouthEast(row, column);
    //sums up the total number of neighbors with the return value from the checkNeighbor() method
    sum = checkNeighbor(currChar1) + checkNeighbor(currChar2) + checkNeighbor(currChar3);

  }else if((row==0) && (column >0) && (column < b->getColumn()-1)){
    //top edge case no corners
    //gets the character from all its neighbors
    currChar1 = b->getAtWest(row, column);
    currChar2 = b->getAtSouthWest(row, column);
    currChar3 = b->getAtSouth(row, column);
    currChar4 = b->getAtSouthEast(row, column);
    currChar5 = b->getAtEast(row, column);
    //sums up the total number of neighbors with the return value from the checkNeighbor() method
    sum = checkNeighbor(currChar1) + checkNeighbor(currChar2) + checkNeighbor(currChar3) + checkNeighbor(currChar4) + checkNeighbor(currChar5);

  } else if((row== b->getRow()-1) && (column >0) && (column < b->getColumn()-1)){
    //bottom edge case  no corners
    //gets the character from all its neighbors
    currChar1 = b->getAtNorth(row, column);
    currChar2 = b->getAtNorthEast(row, column);
    currChar3 = b->getAtNorthWest(row, column);
    currChar4 = b->getAtWest(row, column);
    currChar5 = b->getAtEast(row, column);
    //sums up the total number of neighbors with the return value from the checkNeighbor() method
    sum = checkNeighbor(currChar1) + checkNeighbor(currChar2) + checkNeighbor(currChar3) + checkNeighbor(currChar4) + checkNeighbor(currChar5);

  }else if((row== b->getRow()-1) && (column == b->getColumn()-1)){
    //bottom right corner
    //gets the character from all its neighbors
    currChar1 = b->getAtNorth(row, column);
    currChar2 = b->getAtNorthWest(row, column);
    currChar3 = b->getAtWest(row, column);
    //sums up the total number of neighbors with the return value from the checkNeighbor() method
    sum = checkNeighbor(currChar1) + checkNeighbor(currChar2) + checkNeighbor(currChar3);

  } else if((row== 0) && (column == b->getColumn()-1)){
    //top right corner
    //gets the character from all its neighbors
    currChar1 = b->getAtWest(row, column);
    currChar2 = b->getAtSouthWest(row, column);
    currChar3 = b->getAtSouth(row, column);
    //sums up the total number of neighbors with the return value from the checkNeighbor() method
    sum = checkNeighbor(currChar1) + checkNeighbor(currChar2) + checkNeighbor(currChar3);

  } else if((row== b->getRow()-1) && (column == 0)){
    //bottom left corner case
    //gets the character from all its neighbors
    currChar1 = b->getAtNorth(row, column);
    currChar2 = b->getAtNorthEast(row, column);
    currChar3 = b->getAtEast(row, column);
    //sums up the total number of neighbors with the return value from the checkNeighbor() method
    sum = checkNeighbor(currChar1) + checkNeighbor(currChar2) + checkNeighbor(currChar3);

  } else if((column == 0) && (row>0) && (row < b->getRow()-1)) {
    //left edge case, no corners
    //gets the character from all its neighbors
    currChar1 = b->getAtSouth(row, column);
    currChar2 = b->getAtEast(row, column);
    currChar3 = b->getAtNorth(row, column);
    currChar4 = b->getAtSouthEast(row, column);
    currChar5 = b->getAtNorthEast(row, column);
    //sums up the total number of neighbors with the return value from the checkNeighbor() method
    sum = checkNeighbor(currChar1) + checkNeighbor(currChar2) + checkNeighbor(currChar3) + checkNeighbor(currChar4) + checkNeighbor(currChar5);

  } else if((column == b->getColumn()-1)&& (row >0) && (row< b->getRow()-1)){
    //right edge case, no corners
    //gets the character from all its neighbors
    currChar1 = b->getAtNorth(row, column);
    currChar2 = b->getAtNorthWest(row, column);
    currChar3 = b->getAtWest(row, column);
    currChar4 = b->getAtSouthWest(row, column);
    currChar5 = b->getAtSouth(row, column);
    //sums up the total number of neighbors with the return value from the checkNeighbor() method
    sum = checkNeighbor(currChar1) + checkNeighbor(currChar2) + checkNeighbor(currChar3) + checkNeighbor(currChar4) + checkNeighbor(currChar5);

  }else if((row>0) && (row< b->getRow()) && (column >0) && (column < b->getColumn())) {
    //middle case
    //gets the character from all its neighbors
    currChar1 = b->getAtNorth(row, column);
    currChar2 = b->getAtNorthWest(row, column);
    currChar3 = b->getAtWest(row, column);
    currChar4 = b->getAtSouthWest(row, column);
    currChar5 = b->getAtSouth(row, column);
    currChar6 = b->getAtSouthEast(row, column);
    currChar7 = b->getAtNorthEast(row, column);
    currChar8 = b->getAtEast(row, column);
    //sums up the total number of neighbors with the return value from the checkNeighbor() method
    sum = checkNeighbor(currChar1) + checkNeighbor(currChar2) + checkNeighbor(currChar3) + checkNeighbor(currChar4) + checkNeighbor(currChar5) + checkNeighbor(currChar6) + checkNeighbor(currChar7) + checkNeighbor(currChar8);
  }
  //returns the sum of the coordinates neighbors for classic mode
  return sum;
}

//method to check the rules of mirror mode
int mode::checkMirror(int row, int column, Board *b){
  //gets the sum of thr neighbors inside the grid from the classic method
  int sum = checkClassic(row, column, b);
  char c1;
  char c2;
  char c3;
  //check edge cases and add neighbors to sum
  if(row == 0 && column == 0){
    //top left corner
    //gets the character from all its neighbors in the grid and add to the total from classic
    //these add for the reflection
    c1 = b->getAt(row, column); //location of the corner
    c2 = b->getAtEast(row, column);
    c3 = b->getAtSouth(row, column);
    //sums up the total number of neighbors with the return value from the checkNeighbor() method
    //corner case is multiplied by 3 because in mirror mode it reflects itself 3 ways
    sum += (3*checkNeighbor(c1)) + checkNeighbor(c2) + checkNeighbor(c3);

  }else if((row== b->getRow()-1) && (column == 0)){
    //bottom left corner
    //gets the character from all its neighbors in the grid and add to the total from classic
    //these add for the reflection
    c1 = b->getAt(row, column); //location of the corner
    c2 = b->getAtEast(row, column);
    c3 = b->getAtNorth(row, column);
    //sums up the total number of neighbors with the return value from the checkNeighbor() method
    //corner case is multiplied by 3 because in mirror mode it reflects itself 3 ways
    sum += (3*checkNeighbor(c1)) + checkNeighbor(c2) + checkNeighbor(c3);
  }else if ((row == 0) && (column == b->getColumn()-1)){
    //top right corner
    //gets the character from all its neighbors in the grid and add to the total from classic
    //these add for the reflection
    c1 = b->getAt(row, column); //location of the corner
    c2 = b->getAtWest(row, column);
    c3 = b->getAtSouth(row, column);
    //sums up the total number of neighbors with the return value from the checkNeighbor() method
    //corner case is multiplied by 3 because in mirror mode it reflects itself 3 ways
    sum += (3*checkNeighbor(c1)) + checkNeighbor(c2) + checkNeighbor(c3);

  }else if((row== b->getRow()-1) && (column == b->getColumn()-1)){
    //bottom right corner
    //gets the character from all its neighbors in the grid and add to the total from classic
    //these add for the reflection
    c1 = b->getAt(row, column); //location of the corner
    c2 = b->getAtWest(row, column);
    c3 = b->getAtNorth(row, column);
    //sums up the total number of neighbors with the return value from the checkNeighbor() method
    //corner case is multiplied by 3 because in mirror mode it reflects itself 3 ways
    sum += (3*checkNeighbor(c1)) + checkNeighbor(c2) + checkNeighbor(c3);

  }else if(((row==0) || (row== b->getRow()-1)) && (column >0) && (column < b->getColumn()-1) ){
    //top and bottom edge cases, no corners
    //gets the character from all its neighbors in the grid and add to the total from classic
    //these add for the reflection
    c1 = b->getAt(row, column);
    c2 = b->getAtWest(row, column);
    c3 = b->getAtEast(row, column);
    //sums up the total number of neighbors with the return value from the checkNeighbor() method
    sum += checkNeighbor(c1) + checkNeighbor(c2) + checkNeighbor(c3);
  }else if (((column == b->getColumn()-1) || (column == 0))&& (row >0) && (row< b->getRow()-1)) {
    //left and right edge cases
    //gets the character from all its neighbors in the grid and add to the total from classic
    //these add for the reflection
    c1 = b->getAt(row, column);
    c2 = b->getAtNorth(row, column);
    c3 = b->getAtSouth(row, column);
    //sums up the total number of neighbors with the return value from the checkNeighbor() method
    sum += checkNeighbor(c1) + checkNeighbor(c2) + checkNeighbor(c3);
  }
  //returns the sum for mirror mode
  return sum;
}

//method to check the rules of donut mode
int mode::checkDonut(int row, int column, Board *b){
    //gets the sum from all its neighbors inside the grid from checkClassic()
    int sum = checkClassic(row, column, b);

    char currChar1;
    char currChar2;
    char currChar3;
    char currChar4;
    char currChar5;

    if(row == 0 && column == 0){
      //top left corner
      //gets the character from all its neighbors in the grid and add to the total from classic
      //gets the character for the wrapped coordinates - rules of donut mode
      currChar1 = b->getAt(0, b->getColumn()-1);
      currChar2 = b->getAt(row+1, b->getColumn()-1);
      currChar3 = b->getAt(b->getRow()-1, b->getColumn()-1);
      currChar4 = b->getAt(b->getRow()-1, column + 1);
      currChar5 = b->getAt(b->getRow()-1, column);
      //sums up the total number of neighbors with the return value from the checkNeighbor() method
      sum += checkNeighbor(currChar1) + checkNeighbor(currChar2) + checkNeighbor(currChar3) + checkNeighbor(currChar4) + checkNeighbor(currChar5);
    } else if(row == 0 && (column == b->getColumn()-1)){
      //top right corner
      //gets the character from all its neighbors in the grid and add to the total from classic
      //gets the character for the wrapped coordinates - rules of donut mode
      currChar1 = b->getAt(b->getRow()-1, b->getColumn()-1);
      currChar2 = b->getAt(b->getRow()-1, b->getColumn()-2);
      currChar3 = b->getAt(row, 0);
      currChar4 = b->getAt(row + 1, 0);
      currChar5 = b->getAt(b->getRow()-1, 0);
      //sums up the total number of neighbors with the return value from the checkNeighbor() method
      sum += checkNeighbor(currChar1) + checkNeighbor(currChar2) + checkNeighbor(currChar3) + checkNeighbor(currChar4) + checkNeighbor(currChar5);
    }else if((row == b->getRow()-1) && (column == b->getColumn()-1)){
      //bottom right corner
      //gets the character from all its neighbors in the grid and add to the total from classic
      //gets the character for the wrapped coordinates - rules of donut mode
      currChar1 = b->getAt(0,0);
      currChar2 = b->getAt(0, b->getColumn()-2);
      currChar3 = b->getAt(0, b->getColumn()-1);
      currChar4 = b->getAt(b->getRow()-1, 0);
      currChar5 = b->getAt(b->getRow()-2, 0);
      //sums up the total number of neighbors with the return value from the checkNeighbor() method
      sum += checkNeighbor(currChar1) + checkNeighbor(currChar2) + checkNeighbor(currChar3) + checkNeighbor(currChar4) + checkNeighbor(currChar5);

    }else if((row == b->getRow()-1) && column == 0){
      //bottom left corner
      //gets the character from all its neighbors in the grid and add to the total from classic
      //gets the character for the wrapped coordinates - rules of donut mode
      currChar1 = b->getAt(0,0);
      currChar2 = b->getAt(0, 1);
      currChar3 = b->getAt(0, b->getColumn()-1);
      currChar4 = b->getAt(b->getRow()-1, b->getColumn()-1);
      currChar5 = b->getAt(b->getRow()-2, b->getColumn()-1);
      //sums up the total number of neighbors with the return value from the checkNeighbor() method
      sum += checkNeighbor(currChar1) + checkNeighbor(currChar2) + checkNeighbor(currChar3) + checkNeighbor(currChar4) + checkNeighbor(currChar5);
    }else if((row==0) && (column >0) && (column < b->getColumn()-1)){
      // In between on top row
      //gets the character from all its neighbors in the grid and add to the total from classic
      //gets the character for the wrapped coordinates - rules of donut mode
      currChar1 = b->getAt(b->getRow()-1, column);
      currChar2 = b->getAt(b->getRow()-1, column-1);
      currChar3 = b->getAt(b->getRow()-1, column+1);
      //sums up the total number of neighbors with the return value from the checkNeighbor() method
      sum += checkNeighbor(currChar1) + checkNeighbor(currChar2) + checkNeighbor(currChar3);
    }else if((row == b->getRow()-1) && (column >0) && (column < b->getColumn()-1)){
      // In between on bottom row
      //gets the character from all its neighbors in the grid and add to the total from classic
      //gets the character for the wrapped coordinates - rules of donut mode
      currChar1 = b->getAt(0, column);
      currChar2 = b->getAt(0, column-1);
      currChar3 = b->getAt(0, column+1);
      //sums up the total number of neighbors with the return value from the checkNeighbor() method
      sum += checkNeighbor(currChar1) + checkNeighbor(currChar2) + checkNeighbor(currChar3);

    }else if((column == 0) && (row >0) && (row < b->getRow()-1)){
      // In between left column
      //gets the character from all its neighbors in the grid and add to the total from classic
      //gets the character for the wrapped coordinates - rules of donut mode
      currChar1 = b->getAt(row, b->getColumn()-1);
      currChar2 = b->getAt(row+1, b->getColumn()-1);
      currChar3 = b->getAt(row-1, b->getColumn()-1);
      //sums up the total number of neighbors with the return value from the checkNeighbor() method
      sum += checkNeighbor(currChar1) + checkNeighbor(currChar2) + checkNeighbor(currChar3);
    }else if((column == b->getColumn()-1) && (row > 0) && (row < b->getRow()-1)){
      // In between right column
      //gets the character from all its neighbors in the grid and add to the total from classic
      //gets the character for the wrapped coordinates - rules of donut mode
      currChar1 = b->getAt(row, 0);
      currChar2 = b->getAt(row+1, 0);
      currChar3 = b->getAt(row-1, 0);
      //sums up the total number of neighbors with the return value from the checkNeighbor() method
      sum += checkNeighbor(currChar1) + checkNeighbor(currChar2) + checkNeighbor(currChar3);
    }
    //returns the sum of the neighbors for the specified coordinate for donut mode
    return sum;
}
//checks the character of the neighbor of a coordinate on the grid
int mode::checkNeighbor(char c){
  //checks the characters passed in and returns the 1 if it is an X meaning it is occupied and 0 for every other case
  switch(c){
    case '-':
        return 0;
        break;
    case 'X':
        return 1;
        break;
    default:
        return 0;
        break;
  }
}
//changes the next generation board c based on the number of neighbors and at a specified coordinate
void mode::ruleCheck(int sum, Board *c, char a, int row, int column){
  //switch for each number of neighbors a coordinate can have from 0-4
  //if it has over 4 neighbors it goes through the default
  switch(sum){
    case 0:
    //no neighbors = cell dies
      c->setAt(row, column, '-');
      break;
    case 1:
    //1 neighbor = cell dies
      c->setAt(row, column, '-');
      break;
    case 2:
    //2 neighbors = cell is stable
      c->setAt(row, column, a);
      break;
    case 3:
    //3 neighbors = cell populates
      c->setAt(row, column, 'X');
      break;
    case 4:
    //4 neighbors = dies because of overcrowding
      c->setAt(row, column, '-');
      break;
    default:
    //more than 4 neighbors = dies because of overcrowding
      c->setAt(row, column, '-');
  }

}
