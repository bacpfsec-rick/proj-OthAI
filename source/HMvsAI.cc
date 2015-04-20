/**
 * @file   HMvsAI.cc
 * @Author Bacpfsec Rick
 * @date   20150408
 * @brief  Test program for AI Class
 *
 */
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Othello.h"
#include "AI.h"
#include "HM.h"
using namespace std;

Othello ot;
HM hmX(ot);
AI aiO(ot,'O',506,505,190);

void HMPlay(Othello& ot);
void AIPlay(Othello& ot);

void HMPlay(Othello& ot) {
  cout<<"**** HM PHASE ****"<<endl;
  ot.printBoard();
  ot.printOccupied();
  if (hmX.explore('X')) {
    cout<<"Player X decides to put chess at:";
    hmX.putChess(-1,-1,'X');
    AIPlay(ot);
  } else {
    ot.gameResult();
  }
}

void AIPlay(Othello& ot) {
  cout<<"**** AI PHASE ****"<<endl;
  ot.printBoard();
  ot.printOccupied();
  if (aiO.explore()) {
    aiO.putChess();
    HMPlay(ot);
  } else {
    ot.gameResult();
  }
}

int main() {
  HMPlay(ot);

  return 0;
}
