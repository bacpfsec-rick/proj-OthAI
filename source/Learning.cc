/**
 * @file   Learning.cc
 * @Author Bacpfsec Rick
 * @date   20150408
 * @brief  Program for AI to learn it's proper evaluation
 *
 */
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <time.h>
#include "Othello.h"
#include "AI.h"
#include "HM.h"
#include <iomanip>
using namespace std;

/** X is the learner
 *  O is the companion
 */
bool AIXPlay(AI&, AI&, Othello& ot);
bool AIOPlay(AI&, AI&, Othello& ot);

/* Return true if learner wins
 *
 */
bool AIXPlay(AI& aiX, AI& aiO, Othello& ot) {
  cout<<"**** AI X PHASE ****"<<endl;
  ot.printBoard();
  ot.printOccupied();
  if (aiX.explore()) {
    aiX.putChess();
    return AIOPlay(aiX,aiO,ot);
  } else {
    return ot.gameResult();
  }
}

/* Return true if learner wins
 *
 */
bool AIOPlay(AI& aiX, AI& aiO, Othello& ot) {
  cout<<"**** AI O PHASE ****"<<endl;
  ot.printBoard();
  ot.printOccupied();
  if (aiO.explore()) {
    aiO.putChess();
    return AIXPlay(aiX,aiO,ot);
  } else {
    return ot.gameResult();
  }
}

int main() {
  int wodX = 100, wolX = 100, wowX = 100;
  int wodO = 100, wolO = 100, wowO = 100;
  int count = 0;
  srand(time(NULL));

  ofstream ofs;
  ofs.open("RecordOfLearning");
  ofs<<"The initial weight : "<<wodX<<"\t"<<wolX<<"\t"<<wowX<<endl;
  // Compete and learn against another AI for 100 times
  while (count!=100) {
    Othello ot;
    AI aiX(ot,'X',wodX,wolX,wowX);
    AI aiO(ot,'O',wodO,wolO,wowO);
    bool learnerWin = AIXPlay(aiX,aiO,ot);
    if ( !learnerWin ) { // If lose then learn
      wodX = wodO;
      wolX = wolO;
      wowX = wowO;
      count++;
      ofs<<"The #"<<right<<setw(3)<<count<<"envolve is: "<<wodX<<"\t"<<wolX<<"\t"<<wowX<<endl;
    }
    // face next slightly different opponent
    int i = rand()%3;
    switch (i) {
    case 0:
      wodO += (wodO+wolO+wowO)/10;
      break;
    case 1:
      wolO += (wodO+wolO+wowO)/10;
      break;
    case 2:
      wowO += (wodO+wolO+wowO)/10;
      break;
    default:
      break;
    }
  }

  ofs.close();

  return 0;
}
