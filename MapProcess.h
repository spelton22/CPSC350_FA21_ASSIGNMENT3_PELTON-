/* Sophie Pelton
  2370862
  spelton@chapman.edu
  CPSC350-01
  Assignemnt 3
    MapProcess.cpp
*/

#ifndef MAPPROCESS_H
#define MAPPROCESS_H

#include <iostream>
#include <exception>
#include <stdlib.h>
#include <sstream>
#include "board.h"

using namespace std;

class MapProcess{
  public:
    MapProcess(); //default constructor
    ~MapProcess(); //default destructor

    Board * readFile(string inputFile); //set the contents of input file to map file
      //baord pointer = new board
    Board * makeMap(int row, int col, double density); //creates a random map

};

#endif
