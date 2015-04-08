/**
 * @file   HM.cc
 * @Author Bacpfsec Rick
 * @date   20150408
 * @brief  Implementation of HM Player Class
 *
 */
#include "Othello.h"
#include "HM.h"

HM::HM(Othello& o) : ot(o) {

}

void HM::putChess(int x,int y,char c) {
  if (ot.validMove(x,y,c)) {
    cout<<"HM puts "<<c<<" at ("<<x<<","<<y<<")!"<<endl;
    ot.board[x][y] = c;
    ot.updateAfterPut(x,y,c);
    ot.occupied.push_back(Cord(x,y));
  } else {
    if (!(x==-1 && y==-1)) {
      cout<<c<<" at ("<<x<<","<<y<<") is invalid!"<<endl;
      cout<<"Input new x & y Cord:"<<endl;
    }
    int xx,yy;
    cin>>xx>>yy;
    putChess(xx,yy,c);
  }
}

void HM::printAvaliable() {
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

bool HM::explore(char c) {
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
