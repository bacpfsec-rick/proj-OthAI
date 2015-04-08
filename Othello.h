/**
 * @file   Othello.h
 * @Author Bacpfsec Rick
 * @date   20150407
 * @brief  Header file of Othello Class
 *
 */
#ifndef _OTHELLO_H_
#define _OTHELLO_H_
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include "Cord.h"
using namespace std;

class Othello {
 public:
  /* Default constructor
   *
   */
  Othello();

  /* Print the board function
   *
   */
  void printBoard();

  /* Check if a move is valid
   *
   */
  bool validMove(int,int,char);

  /* Use 8*8 char array to store the board
   * ' ':Empty  'X':Black  'O':White
   */
  char board[8][8];

  /* Helper to initialize the board
   *
   */
  void init();

  /* UpdateAfterPut a new chess
   *
   */
  void updateAfterPut(int,int,char);

  /* Helper to update the board after a valid put
   *
   */
  void updateAfterPut(int,int,char,int,int);

  /** Record the occupied positions */
  vector<Cord> occupied;

  /** Print the occupied vector
   *
   */
  void printOccupied();

  /* Check and print the game result
   *
   * Return true if X wins
   * Return false if O wins or tie game
   */
  bool gameResult();
};

#endif
