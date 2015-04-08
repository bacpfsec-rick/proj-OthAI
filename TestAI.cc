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
AI ai(ot);
HM hm(ot);

int main() {
  /* Test the evaluate */
  while (true) {
    ot.printBoard();
    ai.evaluate('X');
    hm.putChess(-1,-1,'X');    
    ot.printBoard();
    ai.evaluate('O');
    hm.putChess(-1,-1,'O');
  }
  return 0;
}
