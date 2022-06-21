#include <bits/stdc++.h>
using namespace std;
// 처음에는 visited 배열을 3차원으로 잡으려고했으나, 블로그 등을 확인하고 2차원으로하는게 속 편하다는것을 깨달음
int N;
int MAP[55][55];
int visited[55][55];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;
  
  for(int i = 0; i < N; i++) {
    string str; cin >> str;
    for(int j = 0; j < N; j++){
      MAP[i][j] = str[j] - '0';
    }
  }
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      visited[i][j] = 987654321;
    }
  }

  queue<pair<int, int>> q;
  q.push({0, 0}); visited[0][0] = 0;

  while(!q.empty()){
    auto cur = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];
      if(nx < 0 or nx >= N or ny < 0 or ny >= N) continue;
      if(MAP[nx][ny] == 0){ // 검은 방
        if(visited[nx][ny] > visited[cur.first][cur.second] + 1){
          visited[nx][ny] = visited[cur.first][cur.second] + 1;
          q.push({nx, ny});
        }
      }
      if(MAP[nx][ny] == 1){ // 흰 방
        if(visited[nx][ny] > visited[cur.first][cur.second]){
          visited[nx][ny] = visited[cur.first][cur.second];
          q.push({nx, ny});
        }
      }
    }
  }

  cout << visited[N-1][N-1];

}