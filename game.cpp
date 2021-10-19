/* Sophie Pelton
  2370862
  spelton@chapman.edu
  CPSC350-01
  Assignemnt 3
    game.cpp
*/

//this class plays the game and with a given board and writes the changes to a second boards

#include "game.h"

game::game(){ //default constructor
}

game::~game(){ //default destructor

}
//method to play the game of life
//takes in board b for the current board and a baord c for the next generation board
//passes in the mode for the game to play
void game::play(Board *b, Board *c, char mode){
  int sum = 0;
  char a;
  //checks for classic mode
  if(mode == 'C'){
    //for loop to interate over every coordinate of the grid
    for(int i = 0; i < b->getRow(); ++i){
      for(int j = 0 ; j < b->getColumn(); ++j){
        //calls function to check the number of neighbors for the given coordinate for classic mode
        sum = mode::checkClassic(i, j, b);
        //gets the character of the given coordinate
        a = b->getAt(i, j);
        //calls method to handle the changing of the characters
        mode::ruleCheck(sum, c, a, i, j);
      }
    }
  }//checks for mirror mode
  else if(mode == 'M'){
    //for loop to interate over every coordinate of the grid
    for(int i = 0; i < b->getRow(); ++i){
      for(int j = 0 ; j < b->getColumn(); ++j){
        //calls function to check the number of neighbors for the given coordinate for mirror mode
        sum = mode::checkMirror(i, j, b);
        //gets the character of the given coordinate
        a = b->getAt(i, j);
        //calls method to handle the changing of the characters
        mode::ruleCheck(sum, c, a, i, j);
      }
    }
  }//checks for donut mode
  else if(mode == 'D'){
    //for loop to interate over every coordinate of the grid
    for(int i = 0; i < b->getRow(); ++i){
      for(int j = 0 ; j < b->getColumn(); ++j){
        //calls function to check the number of neighbors for the given coordinate for donut mode
        sum = mode::checkDonut(i, j, b);
        //gets the character of the given coordinate
        a = b->getAt(i, j);
        //calls method to handle the changing of the characters
        mode::ruleCheck(sum, c, a, i, j);
      }
    }
  }

}
