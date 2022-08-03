#include <bits/stdc++.h>
using namespace std;

int N, M;
char board[22][22];
bool vis[22][22][22][22];
vector<pair<int, int>> tmp;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool chk(pair<int, int>& coin){
  if(coin.first < 0 or coin.first >= N or coin.second < 0 or coin.second >= M) return true;
  return false;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin >> board[i][j];
      if(board[i][j] == 'o'){
        board[i][j] = '.'; // 빈 칸으로 만들기
        tmp.push_back({i, j});
      }
    }
  }

  queue<tuple<pair<int, int>, pair<int, int>, int>> q;

  q.push({{tmp[0].first, tmp[0].second}, {tmp[1].first, tmp[1].second}, 0});

  while(!q.empty()){
    auto cur = q.front(); q.pop();
    
    pair<int, int> c1 = get<0>(cur);
    pair<int, int> c2 = get<1>(cur);
    int cnt = get<2>(cur);

    if(cnt > 10){
      cout << -1 << "\n";
      return 0;
    }

    // if(vis[c1.first][c1.second][c2.first][c2.second] or vis[c2.first][c2.second][c1.first][c1.second]) continue;
    // vis[c1.first][c1.second][c2.first][c2.second] = true;
    // vis[c2.first][c2.second][c1.first][c1.second] = true;


    

    for(int dir = 0; dir < 4; dir++){
      pair<int, int> new_c1 = {c1.first + dx[dir], c1.second + dy[dir]};
      pair<int, int> new_c2 = {c2.first + dx[dir], c2.second + dy[dir]};
      bool chk1 = chk(new_c1);
      bool chk2 = chk(new_c2);
      if(chk1 and chk2){ // 두개 다 범위 밖
          q.push({c1, c2, cnt + 1});
      }else if(chk1 == false and chk2 == false){ // 두개 다 범위 안
        if(board[new_c1.first][new_c1.second] == '#' and board[new_c2.first][new_c2.second] == '#'){
          q.push({c1, c2, cnt + 1});
        }else if(board[new_c1.first][new_c1.second] == '#'){
          q.push({c1, new_c2, cnt + 1});
        }else if(board[new_c2.first][new_c2.second] == '#'){
          q.push({new_c1, c2, cnt + 1});
        }else{
          q.push({new_c1, new_c2, cnt + 1});
        }
      }else{ // 한개만 범위 안
        if(cnt >= 10){
          cout << -1 << "\n";
          return 0;
        }
        cout << cnt + 1 << "\n";
        return 0;
      }
    }
  }
  return 0;
}