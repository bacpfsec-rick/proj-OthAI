/**
 * @file   Othello.cc
 * @Author Bacpfsec Rick
 * @date   20150407
 * @brief  Implementation of Othello Class
 *
 */
#include "Othello.h"

Othello::Othello() {
  init();
}

void Othello::printBoard() {
  cout<<"--Current Board--"<<endl;
  cout<<setfill('-')<<setw(17)<<""<<endl;
  for(int i=0; i<8; i++) {
    cout<<"|";
    for(int j=0; j<8; j++) {
      cout<<board[i][j]<<(j==7 ? "" : " ");
    }
    cout<<"|"<<endl;
  }
  cout<<setfill('-')<<setw(17)<<"";
  cout<<endl;
}

void Othello::init() {
  for(int i=0; i<8; i++) {
    for(int j=0; j<8; j++) {
      board[i][j] = ' ';
    }
  }
  // 4 init
  board[3][3] = 'O';
  board[4][4] = 'O';
  board[3][4] = 'X';
  board[4][3] = 'X';
  occupied.push_back(Cord(3,3));
  occupied.push_back(Cord(3,4));
  occupied.push_back(Cord(4,3));
  occupied.push_back(Cord(4,4));
}

bool Othello::validMove(int x,int y,char c) {
  if (board[x][y]!=' ') { // occupied
    return false;
  }
  if (x>0) {  // check left
    if(board[x-1][y]!=' ' && board[x-1][y]!=c) {  // c' at left
      for (int j=x-2; j>=0; j--) {
	if(board[j][y]==c) { // met another c
	  return true;
	} else if (board[j][y]==' ') {
	  break;
	}
      }
    }
  }
  if (x<7) { // check right
    if(board[x+1][y]!=' ' && board[x+1][y]!=c) {
      for (int j=x+2; j<=7; j++) {
	if(board[j][y]==c) {
	  return true;
	} else if (board[j][y]==' ') {
	  break;
	}
      }
    }
  }
  if (y>0) { // check up
    if(board[x][y-1]!=' ' && board[x][y-1]!=c) {
      for (int j=y-2; j>=0; j--) {
	if(board[x][j]==c) {
	  return true;
	} else if (board[x][j]==' ') {
	  break;
	}
      }
    }
  }
  if (y<7) { // check down
    if(board[x][y+1]!=' ' && board[x][y+1]!=c) {
      for (int j=y+2; j<=7; j++) {
	if(board[x][j]==c) {
	  return true;
	} else if (board[x][j]==' ') {
	  break;
	}
      }
    }
  }
  if (x>0 && y>0) {  // check up-left
    if(board[x-1][y-1]!=' ' && board[x-1][y-1]!=c) {
      for (int j=2; ((x-j)>=0 && (y-j)>=0); j++) {
	if(board[x-j][y-j]==c) {
	  return true;
	} else if (board[x-j][y-j]==' ') {
	  break;
	}
      }
    }
  }
  if (x>0 && y<7) {  // check up-right
    if(board[x-1][y+1]!=' ' && board[x-1][y+1]!=c) {
      for (int j=2; ((x-j)>=0 && (y+j)<=7); j++) {
	if(board[x-j][y+j]==c) {
	  return true;
	} else if (board[x-j][y+j]==' ') {
	  break;
	}
      }
    }
  }
  if (x<0 && y>0) {  // check down-left
    if(board[x+1][y-1]!=' ' && board[x+1][y-1]!=c) {
      for (int j=2; ((x+j)<=7 && (y-j)>=0); j++) {
	if(board[x+j][y-j]==c) {
	  return true;
	} else if (board[x+j][y-j]==' ') {
	  break;
	}
      }
    }
  }
  if (x<7 && y<7) {  // check down-right
    if(board[x+1][y+1]!=' ' && board[x+1][y+1]!=c) {
      for (int j=2; ((x+j)<=7 && (y+j)<=7); j++) {
	if(board[x+j][y+j]==c) {
	  return true;
	} else if (board[x+j][y+j]==' ') {
	  break;
	}
      }
    }
  }

  return false;
}

void Othello::updateAfterPut(int x,int y,char c) {
  updateAfterPut(x,y,c,0,1);
  updateAfterPut(x,y,c,0,-1);
  updateAfterPut(x,y,c,1,0);
  updateAfterPut(x,y,c,-1,0);
  updateAfterPut(x,y,c,1,1);
  updateAfterPut(x,y,c,1,-1);
  updateAfterPut(x,y,c,-1,1);
  updateAfterPut(x,y,c,-1,-1);
}

void Othello::updateAfterPut(int x,int y,char c,int dx,int dy) {
  int xx=x+dx, yy =y+dy;
  while (xx>=0 && xx<=7 && yy>=0 && yy<=7) {
    if (board[xx][yy]==' ') {
      xx = x;
      yy = y;
      break;
    } else if (board[xx][yy]==c) {
      break;
    } else {
      xx += dx;
      yy += dy;
    }
  }
  if ( (xx>=0 && xx<=7 && yy>=0 && yy<=7) &&
       ( (xx!=x) || (yy!=y) ) ) { // update the cells between
    while(!(xx==x && yy==y)) {
      board[xx][yy] = c;
      xx -= dx;
      yy -= dy;
    }
  }
}

void Othello::printOccupied() {
  cout<<"The occupied cells are:"<<endl;
  for (unsigned int i=0; i<occupied.size(); i++) {
    cout<<"("<<occupied[i].x<<","<<occupied[i].y<<")  ";
    if((i+1)%20==0) {
      cout<<endl;
    }
  }
  if (occupied.size()%20!=0) {
    cout<<endl;
  }
}

bool Othello::gameResult() {
    unsigned int count = 0;
    for(unsigned int i=0; i<occupied.size(); i++) {
      if (board[occupied[i].x][occupied[i].y]=='X') {
	count++;
      }
    }
    cout<<"# of X disks : "<<count<<endl;
    cout<<"# of O disks : "<<(occupied.size()-count)<<endl;
    if (count>(occupied.size()-count)) {
      cout<<"****** X wins ******!"<<endl;
      return true;
    } else if (count<(occupied.size()-count)) {
      cout<<"****** O wins ******!"<<endl;
      return false;
    } else {
      cout<<"TIE GAME!"<<endl;
      return false;
    }
}
