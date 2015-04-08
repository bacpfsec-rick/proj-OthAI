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
  ot.printBoard();
  ai.evaluate('X');

  hm.putChess(-1,-1,'X');
  ai.evaluate('O');

  return 0;
}
