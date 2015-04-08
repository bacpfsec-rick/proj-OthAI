/**
 * @file   Cord.h
 * @Author Bacpfsec Rick
 * @date   20150408
 * @brief  Header file of Cord Class
 *
 */
#ifndef _CORD_H_
#define _CORD_H_
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
using namespace std;

class Cord{
 public:
  Cord();
  Cord(int xx,int yy);
  int x;
  int y;
};

#endif
