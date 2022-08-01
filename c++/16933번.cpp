#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int board[1010][1010];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int vis[11][1010][1010];
vector<int> ans;

typedef struct {
  int x, y, k, dist;
  bool day; // 0 -> 낮, 1 -> 밤
}E;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M >> K;
  for(int i = 0; i < N; i++){ // (0, 0) to (N - 1, M - 1)
    string str;
    cin >> str;
    for(int j = 0; j < M; j++){
      board[i][j] = str[j] - '0';
    }
  }

  queue<E> q;
  q.push({0, 0, 0, 1, 0});
  vis[0][0][0] = 1;
  while(!q.empty()){
    auto cur = q.front();
    q.pop();

    if(cur.x == N - 1 and cur.y == M - 1){
      ans.push_back(cur.dist);
    }
    
    for(int dir = 0; dir < 4; dir++){
      int nx = cur.x + dx[dir];
      int ny = cur.y + dy[dir];
      if(nx < 0 or nx >= N or ny < 0 or ny >= M) continue;

      // 밤이고, 부술 수 있는 기회가 남아있고, 벽인 곳에 이동하고자한다면, 기다린다.
      if(cur.day == true and board[nx][ny] == 1 and vis[cur.k][cur.x][cur.y] == 1 and cur.k < K){
        vis[cur.k][cur.x][cur.y]++;
        q.push({cur.x, cur.y, cur.k, cur.dist + 1, !cur.day});
      }

      // 밤이고, 벽이 아닌 곳으로 이동한다.
      if(cur.day == true and board[nx][ny] == 0 and vis[cur.k][nx][ny] == 0){
        vis[cur.k][nx][ny]++;
        q.push({nx, ny, cur.k, cur.dist + 1, !cur.day});
      }

      // 낮이고, 벽이 있으면 부수고 이동한다.
      if(cur.day == false and board[nx][ny] == 1 and cur.k + 1 <= K and vis[cur.k + 1][nx][ny] == 0){
        vis[cur.k + 1][nx][ny]++;
        q.push({nx, ny, cur.k + 1, cur.dist + 1, !cur.day});
      }

      // 낮이고, 벽이 아닌 곳으로 이동한다.
      if(cur.day == false and board[nx][ny] == 0 and vis[cur.k][nx][ny] == 0){
        vis[cur.k][nx][ny]++;
        q.push({nx, ny, cur.k, cur.dist + 1, !cur.day});
      }
    }
  }
  if(ans.empty()){
    cout << -1 << "\n";
  }else{
    sort(ans.begin(), ans.end());
    cout << ans.front() << "\n";
  }
  return 0;
}

/*

0110

0ㅁ10
0ㅁ10
01ㅁ0
010ㅁ

*/