#include <bits/stdc++.h>
using namespace std;

int board[101][101];
bool visited[101][101];
int N;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void DFS(int x, int y, int cnt){
  visited[x][y] = true;
  board[x][y] = cnt;

  for(int dir = 0; dir < 4; dir++){
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(nx < 0 or nx >= N or ny < 0 or ny >= N) continue;
    if(board[nx][ny] and !visited[nx][ny]) DFS(nx, ny, cnt);
  }
}

int BFS(int cnt){
  queue<pair<int, int>> q;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(board[i][j] == cnt){
        visited[i][j] = true;
        q.push({i, j});
      }
    }
  }
  int res = 0;
  while(!q.empty()){
    int cur_size = q.size();
    for(int i = 0; i < cur_size; i++){
      int x = q.front().first;
      int y = q.front().second;
      q.pop();

      for(int dir = 0; dir < 4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 or nx >= N or ny < 0 or ny >= N) continue;
        if(board[nx][ny] != 0 and board[nx][ny] != cnt){
          return res;
        }else if(board[nx][ny] == 0 and !visited[nx][ny]){
          visited[nx][ny] = true;
          q.push({nx, ny});
        }
      }
    }
    res++;
  }
  return 978523;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++) cin >> board[i][j];
  }

  int cnt = 1;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(board[i][j] and !visited[i][j]){
        DFS(i, j, cnt++);
      }
    }
  }

  int ans = 987654321;
  for(int i = 1; i < cnt; i++){
    memset(visited, 0, sizeof visited);
    ans = min(ans, BFS(i));
  }


  cout << ans << '\n';
  return 0;
}