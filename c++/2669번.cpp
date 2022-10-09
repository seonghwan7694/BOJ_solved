#include <bits/stdc++.h>
using namespace std;

bool board[202][202];
int cnt;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  for(int i = 0; i < 4; i++){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for(int j = x1; j < x2; j++){
      for(int k = y1; k < y2; k++){
        board[j][k] = true;
      }
    }
  }

  for(int i = 0; i < 101; i++){
    for(int j = 0; j < 101; j++){
      if(board[i][j]) cnt++;
    }
  }
  cout << cnt << "\n";
  return 0;
}