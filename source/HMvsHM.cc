/**
 * @file   HMvsHM.cc
 * @Author Bacpfsec Rick
 * @date   20150407
 * @brief  Simple version as HM vc HM Othello game
 *
 */
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Othello.h"
#include "HM.h"
using namespace std;

/** global vars */
Othello ot;
HM playerX(ot);
HM playerO(ot);

void PlayX(Othello&);
void PlayO(Othello&);

void PlayX(Othello& ot) {
  ot.printBoard();
  ot.printOccupied();
  if (playerX.explore('X')) {
    cout<<"Player X decides to put chess at:";
    playerX.putChess(-1,-1,'X');
    PlayO(ot);
  } else {
    ot.gameResult();
  }
}

void PlayO(Othello& ot) {
  ot.printBoard();
  ot.printOccupied();
  if (playerO.explore('O')) {
    cout<<"Player O decides to put chess at:";
    playerO.putChess(-1,-1,'O');
    PlayX(ot);
  } else {
    ot.gameResult();
  }
}

int main() {
  PlayX(ot);

  return 0;
}
