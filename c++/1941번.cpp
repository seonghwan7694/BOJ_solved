#include <bits/stdc++.h>
using namespace std;

bool chk[25];
vector<string> board(5);
bool vis[5][5];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  for(int i = 18; i < 25; i++){
    chk[i] = true;
  }
  for(int i = 0; i < 5; i++){
    string str;
    cin >> str;
    board[i] = str;
  }

  int ans = 0;
  do{
    int S_cnt = 0;
    for(int i = 0; i < 25; i++){
      if(chk[i] and board[i/5][i%5] == 'S') S_cnt++;
    }
    if(S_cnt >= 4){
      int tmp_i;
      int tmp_j;
      memset(vis, false, sizeof vis);
      for(int i = 0; i < 25; i++){
        if(chk[i]){
          tmp_i = i/5;
          tmp_j = i%5;
          break;
        }
      }
      queue<pair<int, int>> q;
      int cnt = 1;
      vis[tmp_i][tmp_j] = true;
      q.push({tmp_i, tmp_j});
      while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++){
          int nx = cur.first + dx[dir];
          int ny = cur.second + dy[dir];
          if(nx < 0 or nx >= 5 or ny < 0 or ny >= 5) continue;
          if(vis[nx][ny] or chk[nx*5 + ny] == false) continue;
          cnt++;
          vis[nx][ny] = true;
          q.push({nx, ny});
        }
      }
      if(cnt == 7) ans++;
    }
  }while(next_permutation(chk, chk + 25));


  cout << ans << "\n";
  return 0;
}