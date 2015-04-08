/**
 * @file   TestOth.cc
 * @Author Bacpfsec Rick
 * @date   20150407
 * @brief  Test program for Othello Class
 *
 */
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Othello.h"
using namespace std;

int main() {
  Othello ot;
  /* test printBoard() & init() */
  /*
  ot.printBoard();
  */

  /* test validMove(i,i,c) */
  /*
  cout<<"validMove(2,3,'X') : "<<ot.validMove(2,3,'X')<<endl;
  cout<<"validMove(2,3,'O') : "<<ot.validMove(2,3,'O')<<endl;
  cout<<"validMove(4,5,'X') : "<<ot.validMove(4,5,'X')<<endl;
  cout<<"validMove(4,5,'O') : "<<ot.validMove(4,5,'O')<<endl;
  cout<<"validMove(3,5,'X') : "<<ot.validMove(3,5,'X')<<endl;
  cout<<"validMove(3,5,'O') : "<<ot.validMove(3,5,'O')<<endl;
  cout<<"validMove(5,3,'X') : "<<ot.validMove(5,3,'X')<<endl;
  cout<<"validMove(5,3,'O') : "<<ot.validMove(5,3,'O')<<endl;
  cout<<"validMove(1,1,'X') : "<<ot.validMove(1,1,'X')<<endl;
  cout<<"validMove(6,6,'O') : "<<ot.validMove(6,6,'O')<<endl;
  cout<<"validMove(3,3,'X') : "<<ot.validMove(3,3,'X')<<endl;
  cout<<"validMove(3,3,'O') : "<<ot.validMove(3,3,'O')<<endl;
  */

  /* test putChessHM(i,i,c) */
  ot.printBoard();
  while(true) {
    ot.printBoard();
    ot.printOccupied();
    ot.explore('X');
    ot.putChessHM(-1,-1,'X');
    ot.printBoard();
    ot.printOccupied();
    ot.explore('O');
    ot.putChessHM(-1,-1,'O');
  }


  return 0;
}
