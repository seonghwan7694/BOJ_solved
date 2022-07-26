#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
int board[30][30];
bool road[30][30];
bool floyd(){
  bool flag = false;
  for(int k = 1; k <= N; k++){
    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= N; j++){
        if(i == j or j == k or i == k) continue;
        if(board[i][j] > board[i][k] + board[k][j]) flag = true;
        else if(board[i][j] == board[i][k] + board[k][j]){ // 직접가는 경로가 거쳐가는 경로와 같다면, 직접가는 경로를 삭제한다.
          road[i][j] = false;
        }
      }
    }
  }
  return flag;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> N;
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      cin >> board[i][j];
    }
  }
  memset(road, true, sizeof road);
  if(floyd()){
    cout << -1 << "\n";
    return 0;
  }
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      if(road[i][j]) ans += board[i][j];
    }
  }
  cout << ans/2 << "\n";
  return 0;
}