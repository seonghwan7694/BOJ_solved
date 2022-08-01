#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[55][55];
int dist[55][55];
bool vis[55][55];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
const int INF = 987654321;
int zero_cnt;
int ans = INF;
vector<int> combi;
vector<pair<int, int>> virus; // 5

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M; // 3
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> board[i][j];
      if(board[i][j] == 2){
        virus.push_back({i, j});
      }
    }
  }
  for(int i = 0; i < virus.size() - M; i++){ // 2
    combi.push_back(0);
  }
  for(int i =0 ; i < M; i++){
    combi.push_back(1);
  }

  do{
    memset(dist, -1, sizeof dist);
    memset(vis, 0, sizeof vis);

    queue<pair<int, int>> q;
    for(int i = 0; i < combi.size(); i++){
      if(combi[i] == 1){
        dist[virus[i].first][virus[i].second] = 0;
        vis[virus[i].first][virus[i].second] = true;
        q.push({virus[i]});
      }
    }

    while(!q.empty()){
      auto cur = q.front(); q.pop();

      for(int dir = 0; dir < 4; dir++){
        int nx = cur.first + dx[dir];
        int ny = cur.second + dy[dir];
        if(nx < 0 or nx >= N or ny < 0 or ny >= N or board[nx][ny] == 1 or vis[nx][ny]) continue;
        
        if(board[nx][ny] == 0){
          dist[nx][ny] = dist[cur.first][cur.second] + 1;
          vis[nx][ny] = true;
          q.push({nx, ny});
        }
        if(board[nx][ny] == 2){
          dist[nx][ny] = dist[cur.first][cur.second];
          vis[nx][ny] == true;
          q.push({nx, ny});
        }
      }
    }

    bool flag = false;
    int tmp_ans = -INF;
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        tmp_ans = max(tmp_ans, dist[i][j]);
        if(board[i][j] == 0 and dist[i][j] == -1){ // 빈칸인데 바이러스가 도달 안했다?
          flag = true;
        }
      }
    }
    if(!flag){
      ans = min(tmp_ans, ans);
    }
  }while(next_permutation(combi.begin(), combi.end()));

  if(ans == INF){
    cout << -1 << "\n";
  }else{
    cout << ans << "\n";
  }
  return 0;
}