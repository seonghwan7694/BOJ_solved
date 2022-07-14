#include <bits/stdc++.h>
using namespace std;

int board[9][9];
bool flag;

void func(int k){
  if(flag) return;
  if(k == 81){
    for(int i = 0; i < 9; i++){
      for(int j = 0; j < 9; j++){
        cout << board[i][j];
      }
      cout << "\n";
    }
    flag = true;
    return;
  }

  int x = k / 9;
  int y = k % 9;
  if(board[x][y] != 0) func(k + 1);
  else{
    for(int i = 1; i < 10; i++){
      bool tmp = true;
      for(int j = 0; j < 9; j++){
        if(board[x][j] == i or board[j][y] == i){
          tmp = false;
          break;
        }
      }
      if(!tmp) continue;
      int nx = (x/3)*3;
      int ny = (y/3)*3;
      for(int j = nx; j < nx + 3; j++){
        for(int k = ny; k < ny + 3; k++){
          if(board[j][k] == i) {
            tmp = false;
            break;
          }
        }
        if(!tmp) break;
      }
      if(tmp){
        board[x][y] = i;
        func(k + 1);
        board[x][y] = 0;
      }

    }
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  for(int i = 0; i < 9; i++){
    string str; cin >> str;
    for(int j = 0; j < 9; j++){ board[i][j] = str[j] - '0'; }
  }
  func(0);
  return 0;
}