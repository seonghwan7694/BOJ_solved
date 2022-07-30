#include <bits/stdc++.h>
using namespace std;

int N, M, T;
int board[101][101];
int dist[101][101];
bool vis[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int gram_x, gram_y;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M >> T;
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= M; j++){
      cin >> board[i][j];
      if(board[i][j] == 2){
        gram_x = i;
        gram_y = j;
      }
    }
  }

  queue<pair<int, pair<int, int>>> q;
  q.push({0, {1, 1}});
  vis[1][1] = true;
  dist[1][1] = 0;
  while(!q.empty()){
    auto cur = q.front();
    q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.second.first + dx[dir];
      int ny = cur.second.second + dy[dir];
      if(nx < 1 or nx > N or ny < 1 or ny > M or vis[nx][ny] or board[nx][ny] == 1) continue;
      q.push({cur.first + 1, {nx, ny}});
      vis[nx][ny] = true;
      dist[nx][ny] = cur.first + 1;
    }
  }
  if(vis[N][M] == true and vis[gram_x][gram_y] == false and dist[N][M] <= T){ // 목표에 도착, 그람 안 들고감, 제한 시간 내
    cout << dist[N][M] << "\n";
  }else if(vis[N][M] == true and vis[gram_x][gram_y] == true and (dist[N][M] <= T or dist[gram_x][gram_y] + (N - gram_x) + (M - gram_y) <= T)){ // 목표에 도착, 그람을 들었음, 
    cout << min(dist[N][M], dist[gram_x][gram_y] + (N - gram_x) + (M - gram_y)) << "\n";
  }else if((vis[N][M] == false and vis[gram_x][gram_y] == true) and dist[gram_x][gram_y] + (N - gram_x) + (M - gram_y) <= T){
    cout << dist[gram_x][gram_y] + (N - gram_x) + (M - gram_y) << "\n";
  }else{
    cout << "Fail" << "\n";
  }
  
  return 0;
}