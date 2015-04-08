/**
 * @file   HM.h
 * @Author Bacpfsec Rick
 * @date   20150408
 * @brief  Header file of HM Player Class
 *
 */
#ifndef _HM_H_
#define _HM_H_
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include "Othello.h"
#include "Cord.h"
using namespace std;

class HM {
 public:
  /* Constructor to read the reference to the board
   *
   */
  HM(Othello&);

  /* Put a chess on the referenced board
   *
   */
  void putChess(int,int,char);

  /** Store a reference to the board */
  Othello& ot;

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

};

#endif
