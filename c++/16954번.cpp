#include <bits/stdc++.h>
using namespace std;

int board[10][10];
int dx[9] = {-1, 1, 0, 0, 1, 1, -1, -1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
bool visited[9][9][9];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  for(int i = 0; i < 8; i++){
    string str; cin >> str;
    for(int j = 0; j < 8; j++){
      if(str[j] == '.') board[i][j] = 0;
      else{
        board[i][j] = 1; // 벽
      }
    }
  }
  // 왼쪽 아래 -> 오른쪽 위
  queue<tuple<int, int, int>> q;
  q.push({0, 7, 0});

  while(!q.empty()){
    auto cur = q.front(); q.pop();
    if(get<1>(cur) == 0 and get<2>(cur) == 7 and visited[get<1>(cur)][get<2>(cur)] == 0){
      cout << 1 << "\n";
      return 0;
    }else if(get<0>(cur) > 9){
      cout << 1 << "\n";
      return 0;
    }

    for(int dir = 0; dir < 9; dir++){
      int nt = get<0>(cur) + 1;
      int nx = get<1>(cur) + dx[dir];
      int ny = get<2>(cur) + dy[dir];
      if(nx < 0 or nx >= 8 or ny < 0 or ny >= 8) continue;
      if(nx - get<0>(cur) >= 0 and board[nx - get<0>(cur)][ny] == 1) continue;
      if(nx - get<0>(cur) - 1 >= 0 and board[nx - get<0>(cur) - 1][ny] == 1) continue;
      if(!visited[get<0>(cur) + 1][nx][ny]){
        q.push({nt, nx, ny});
        visited[nt][nx][ny] = true;
      }
    }
  }
  cout << 0 << "\n";
  return 0;
}