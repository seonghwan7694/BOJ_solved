#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool vis[101][101];
int board[101][101];
int n, m;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  while(true){
    cin >> n >> m;
    if(!n and !m) break;
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n; i++){
      string str; cin >> str;
      for(int j = 0; j < m; j++){
        if(str[j] == '*') board[i][j] = 0;
        else board[i][j] = 1;
      }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(board[i][j] == 1 and !vis[i][j]){
          queue<pair<int, int>> q;
          ans++;
          q.push({i, j});
          vis[i][j] = true;
          while(!q.empty()){
            auto cur = q.front(); q.pop();
            for(int dir = 0; dir < 8; dir++){
              int nx = cur.first + dx[dir];
              int ny = cur.second + dy[dir];
              if(nx < 0 or nx >= n or ny < 0 or ny >= m or vis[nx][ny] or board[nx][ny] == 0) continue;
              q.push({nx, ny});
              vis[nx][ny] = true;
            }
          }
        }
      }
    }
    cout << ans << "\n";
  }


  return 0;
}