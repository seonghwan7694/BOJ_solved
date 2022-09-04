#include <bits/stdc++.h>
using namespace std;

int board[5][5];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 4; j++){
      cin >> board[i][j];
      board[i][4] += board[i][j];
    }
  }

  int a = 0, b = 0;
  for(int i = 0; i < 5; i++){
    if(b < board[i][4]){
      b = board[i][4];
      a = i;
    }
  }
  cout << a + 1 << " " << b << "\n";
  return 0;
}