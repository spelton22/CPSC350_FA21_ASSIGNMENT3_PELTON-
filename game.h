/* Sophie Pelton
  2370862
  spelton@chapman.edu
  CPSC350-01
  Assignemnt 3
    game.h
*/

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <exception>
#include <string>
#include <stdio.h>
#include "board.h"
#include "mode.h"

using namespace std;

class game{
  public:
    game(); //default constructor
    ~game(); //default constructor
    void play(Board *b, Board *c, char mode);
    //plays the game with a passed in board b and copies the changes to the next board c while being mode aware
};

#endif
