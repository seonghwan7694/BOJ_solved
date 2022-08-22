#include <bits/stdc++.h>
using namespace std;

int n;
int board[501][501], dp[501][501]; // 임의의 점에서 시작, dp[x][y]가 끝
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int DFS(int x, int y){
  if(dp[x][y] != 0) return dp[x][y];
  dp[x][y] = 1;

  for(int dir = 0; dir < 4; dir++){
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
    if(board[x][y] < board[nx][ny]){

      dp[x][y] = max(dp[x][y], DFS(nx, ny) + 1);
    }
  }
  return dp[x][y];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> n;
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> board[i][j];
    }
  }

  int ans = -1;
  
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      ans = max(ans, DFS(i, j));
    }
  }
  cout << ans << "\n";
  return 0;
}