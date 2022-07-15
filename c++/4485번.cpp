#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int N;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int solution(){
  int board[126][126] = {0};
  int visited[126][126] = {0};

  for(int i = 0; i < N; i++){
    fill(visited[i], visited[i] + N, INF);
    for(int j = 0; j < N; j++){
      cin >> board[i][j];
    }
  }


  queue<pair<int, int>> q;
  q.push({0, 0});
  visited[0][0] = board[0][0];

  while(!q.empty()){
    auto cur = q.front(); q.pop();

    for(int dir = 0; dir < 4; dir++){
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];
      if(nx < 0 or nx >= N or ny < 0 or ny >= N) continue;
      if(visited[nx][ny] > board[nx][ny] + visited[cur.first][cur.second]){
        visited[nx][ny] = board[nx][ny] + visited[cur.first][cur.second];
        q.push({nx, ny});
      }
    }
  }
  return visited[N - 1][N - 1];

}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int tc = 1;
  while(true){
    cin >> N;
    if(!N) break;
    cout << "Problem " << tc++ << ": " << solution() << "\n";
  }
  return 0;
}