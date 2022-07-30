#include <bits/stdc++.h>
using namespace std;

int n, m;
int target_x, target_y;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int board[1010][1010];
bool vis[1010][1010];
int ans[1010][1010];
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> board[i][j];
      if(board[i][j] == 2){
        target_x = i;
        target_y = j;
      }
    }
  }
  queue<pair<int, pair<int, int>>> q;
  q.push({0, {target_x, target_y}});
  vis[target_x][target_y] = true;
  ans[target_x][target_y] = 0;
  while(!q.empty()){
    auto cur = q.front();
    q.pop();

    for(int dir = 0; dir < 4; dir++){
      int nx = cur.second.first + dx[dir];
      int ny = cur.second.second + dy[dir];
      if(nx < 0 or nx >= n or ny < 0 or ny >= m or vis[nx][ny] or board[nx][ny] == 0) continue; 
      q.push({cur.first + 1, {nx, ny}});
      vis[nx][ny] = true;
      ans[nx][ny] = cur.first + 1;
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(vis[i][j] == false and board[i][j] == 1){
        ans[i][j] = -1;
      }
    }
  }
  for(int i = 0; i < n ; i++){
    for(int j = 0; j < m; j++){
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}