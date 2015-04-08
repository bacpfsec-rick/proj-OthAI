/**
 * @file   AI.cc
 * @Author Bacpfsec Rick
 * @date   20150408
 * @brief  Implementation of AI Player Class
 *
 */
#include "Othello.h"
#include "AI.h"

AI::AI(Othello& o, int d, int l, int w) :
  ot(o), wod(d), wol(l), wow(w) {

}

void AI::printAvaliable() {
  cout<<"The avaliable cells are:"<<endl;
  for (unsigned int i=0; i<avaliable.size(); i++) {
    cout<<"["<<avaliable[i].x<<","<<avaliable[i].y<<"]  ";
    if((i+1)%20==0) {
      cout<<endl;
    }
  }
  if (avaliable.size()%20!=0) {
    cout<<endl;
  }
}

bool AI::explore(char c) {
  // reset the avaliable
  avaliable.clear();
  for (int i=0; i<8; i++) {
    for (int j=0; j<8; j++) {
      if(ot.validMove(i,j,c)) {
	  avaliable.push_back(Cord(i,j));
	}
    }
  }
  if (avaliable.size()==0) {
    return false;
  } else {
    printAvaliable();
    return true;
  }
}

int AI::evaluate(char c) {
  explore(c);
  int nol = avaliable.size(), nod = 0, now = 0;
  int result = 0;
  for (unsigned int i=0; i<ot.occupied.size(); i++) {
    int x = ot.occupied[i].x, y = ot.occupied[i].y;
    if (ot.board[x][y]==c) {
      nod += 1;
      if(x%7==0 && y%7==0) { // corner weight is 3
	now += 3;
      } else if (x%7==0 || y%7==0) { // side weight is 2
	now += 2;
      } else { // center weight is 1
	now += 1;
      }
    }
  }
  // Basic result
  result  = nod*wod + nol*wod + now*wow;
  // Consider nol==0 as end of game
  if (nol==0) {
    unsigned int r = (unsigned)nod;
    if (r>ot.occupied.size()) { // win
      result += 9999;
    } else { // lose or tie
      result -= 9999;
    }
  }
  // Print the current status
  cout<<"Current # of disk: "<<nod<<endl;
  cout<<"Current # of legal moves: "<<nol<<endl;
  cout<<"Current disk weights: "<<now<<endl;
  cout<<"Current evaluation: "<<result<<endl;
  return result;
}
