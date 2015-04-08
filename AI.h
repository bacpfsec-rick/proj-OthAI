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
#include "Othello.h"
#include "Cord.h"
using namespace std;

class AI {
 public:
   /* Constructor to read the reference and get weights for evalution
   *
   */
  AI(Othello&,int d = 1,int l = 1,int w = 1);

  /** Update the vector avaliable cells before taking a movement */
  vector<Cord> avaliable;

  /** Print the avaliable vector
   *
   */
  void printAvaliable();

  /** Explore to get the avaliable cells
   *
   */
  bool explore(char);

  /** Evaluate the current status */
  int evaluate(char c);

  /** Store the reference to Othello */
  Othello& ot;

  /** Date record of numbers & weight combination */
  int wod, wol, wow;



};

#endif
