#include <bits/stdc++.h>
using namespace std;
int board[19][19];

int dagaksun_1[6][2] = {
  {-3, -3},
  {-2, -2},
  {-1, -1},
  {1, 1},
  {2, 2},
  {3, 3}
};
int dagaksun_2[6][2] = {
  {3, -3},
  {2, -2},
  {1, -1},
  {-1, 1},
  {-2, 2},
  {-3, 3}
};
int garo[6][2] = {
  {0, -3},
  {0, -2},
  {0, -1},
  {0, 1},
  {0, 2},
  {0, 3}
};
int saro[6][2] = {
  {-3, 0},
  {-2, 0},
  {-1, 0},
  {1, 0},
  {2, 0},
  {3, 0}
};

void SOLVED(int x, int y, int p[6][2]){
  if((0 <= x + p[0][0] and x + p[0][0] < 19) and (0 <= y + p[0][1] and y + p[0][1] < 19)) if(board[x][y] == board[x + p[0][0]][y + p[0][1]]) return;
  if((0 <= x + p[5][0] and x + p[5][0] < 19) and (0 <= y + p[5][1] and y + p[5][1] < 19)) if(board[x][y] == board[x + p[5][0]][y + p[5][1]]) return;

  for(int k = 1; k <= 4; k++){
    if(x + p[k][0] < 0 or x + p[k][0] >= 19 or y + p[k][1] < 0 or y + p[k][1] >= 19) return;
    if(board[x][y] != board[x + p[k][0]][y + p[k][1]]) return;
  }

  cout << board[x][y] << "\n";
  cout << x + p[1][0] + 1 << " " << y + p[1][1] + 1 << "\n";
  exit(0);
  return;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie();

  for(int i = 0; i < 19; i++){
    for(int j = 0; j < 19; j++){
      cin >> board[i][j];
    }
  }

  for(int i = 0; i < 19; i++){
    for(int j = 0; j < 19; j++){
      if(board[i][j]){
        SOLVED(i, j, dagaksun_1);
        SOLVED(i, j, dagaksun_2);
        SOLVED(i, j, garo);
        SOLVED(i, j, saro);
      }
    }
  }

  cout << 0 << "\n";
  return 0;
}