#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[50][50];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visited[50][50][1 << 6];

typedef struct{
  int x;
  int y;
  int cnt;
  int key;
}State;

State get(int x, int y, int cnt, int key){
  State tmp;
  tmp.x = x;
  tmp.y = y;
  tmp.cnt = cnt;
  tmp.key = key;
  return tmp;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  queue<State> q;
  for(int i = 0; i < N; i++){
    string str; cin >> str;
    for(int j = 0; j < M; j++){
      board[i][j] = (int) str[j];
      if(board[i][j] == '0'){
        q.push(get(i, j, 0, 0)); visited[i][j][0] = true;
      }
    }
  }

  while(!q.empty()){
    auto cur = q.front(); q.pop();
    if(board[cur.x][cur.y] == '1'){
      cout << cur.cnt << "\n";
      return 0;
    }

    for(int dir = 0; dir < 4; dir++){
      int nx = cur.x + dx[dir];
      int ny = cur.y + dy[dir];
      if(nx < 0 or nx >= N or ny < 0 or ny >= M or visited[nx][ny][cur.key]) continue;
      if(board[nx][ny] == '.' or board[nx][ny] == '1' or board[nx][ny] == '0'){
        q.push(get(nx, ny, cur.cnt + 1, cur.key)); visited[nx][ny][cur.key] = true;
      }else if('A' <= board[nx][ny] and board[nx][ny] <= 'F'){
        if(cur.key & (1 << (int(board[nx][ny] - 'A')))){
          q.push(get(nx, ny, cur.cnt + 1, cur.key)); visited[nx][ny][cur.key] = true;
        }
      }else if('a' <= board[nx][ny] and board[nx][ny] <= 'f'){
        int tmp_key = cur.key | (1 << (int(board[nx][ny] - 'a')));
        q.push(get(nx, ny, cur.cnt + 1, tmp_key)); visited[nx][ny][tmp_key] = true;
      }
    }
  }
  cout << -1 << "\n";
  return 0;
}