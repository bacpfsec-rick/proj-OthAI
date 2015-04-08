/**
 * @file   TestAI.cc
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
AI aix(ot,'X');
AI aio(ot,'O');
HM hm(ot);

int main() {
  /* Test the evaluate */
  while (true) {
    ot.printBoard();
    aix.evaluate();
    hm.putChess(-1,-1,'X');    
    ot.printBoard();
    aio.evaluate();
    aio.putChess();
    //    hm.putChess(-1,-1,'O');
  }
  return 0;
}
