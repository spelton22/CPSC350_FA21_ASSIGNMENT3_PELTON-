/* Sophie Pelton
  2370862
  spelton@chapman.edu
  CPSC350-01
  Assignemnt 3
    mode.h
*/

#ifndef mode_h
#define mode_h

#include <iostream>
#include <exception>
#include "MapProcess.h"
#include "board.h"
//#include "game.h"

using namespace std;

class mode{
public:

  // default constructor
  mode();
  // default destructor
  ~mode();

  //Methods
  static int checkClassic(int row, int col, Board *b);
  /*returns the sum of the neighbors a coordinate from a board b is passed in and the number of neighbors for that point are checked for classic mode
  */
  static int checkMirror(int row, int col, Board *b);
  /*returns the sum of the neighbors a coordinate from a board b is passed in and the number of neighbors for that point are checked for mirror mode
  */
  static int checkDonut(int row, int col, Board *b);
  /*returns the sum of the neighbors a coordinate from a board b is passed in and the number of neighbors for that point are checked for donut mode */
  static int checkNeighbor(char c);
  //method to check if the neighbor of a point is empty or occupied
  //returns 1 if it is occupied and 0 if it is empty
  static void ruleCheck(int sum, Board *c, char a, int row, int column);
  /*takes the number of neighbors, the board, the character at the point (row, column) in as a parameter and writes the changes of the point to the board c which is the next generation board */
};

#endif
