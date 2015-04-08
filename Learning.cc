/**
 * @file   AIvsAI.cc
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
AI aiX(ot,'X',1,2,3);
AI aiO(ot,'O',1,2,3);

void AIXPlay(Othello& ot);
void AIOPlay(Othello& ot);

void AIXPlay(Othello& ot) {
  cout<<"**** AI X PHASE ****"<<endl;
  ot.printBoard();
  ot.printOccupied();
  if (aiX.explore()) {
    aiX.putChess();
    AIOPlay(ot);
  } else {
    ot.gameResult();
  }
}

void AIOPlay(Othello& ot) {
  cout<<"**** AI O PHASE ****"<<endl;
  ot.printBoard();
  ot.printOccupied();
  if (aiO.explore()) {
    aiO.putChess();
    AIXPlay(ot);
  } else {
    ot.gameResult();
  }
}

int main() {
  AIXPlay(ot);

  return 0;
}
