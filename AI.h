/**
 * @file   AI.h
 * @Author Bacpfsec Rick
 * @date   20150408
 * @brief  Header file of AI Player Class
 *
 */
#ifndef _AI_H_
#define _AI_H_
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include "Othello.h"
#include "Cord.h"
using namespace std;

class AI {
 public:
   /* Constructor to read the reference and get weights for evalution
   *
   */
  AI(Othello&,char c = 'X', int d = 1,int l = 1,int w = 1);

  /** Update the vector avaliable cells before taking a movement */
  vector<Cord> avaliable;

  /** Print the avaliable vector
   *
   */
  void printAvaliable();

  /** Explore to get the avaliable cells
   *
   */
  bool explore();

  /** Evaluate the current status */
  int evaluate();

  /** Alpha-beta search 
   *
   *  alphaBetaSearch(Othello,limit)
   *  maxValue(Othello,a,b,curr,limit)
   *  minValue(othello,a,b,curr,limit)
   */
  Cord alphaBetaSearch(int&, int);
  int maxValue(AI,int,int,int,int);
  int minValue(AI,int,int,int,int);

  /* Put a chess
   *
   */
  void putChess();

  /** Store the reference to Othello */
  Othello& ot;

  /** Char indicates for the AI side */
  char xo;

  /** Date record of numbers & weight combination */
  int wod, wol, wow;
};

#endif
