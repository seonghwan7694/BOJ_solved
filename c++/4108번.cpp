#include <bits/stdc++.h>
using namespace std;

int N, M, board[100][100];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
void BFS(int x, int y){
  for(int dir = 0; dir < 8; dir++){
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(nx < 0 or nx >= N or ny < 0 or ny >= M) continue;
    board[nx][ny]++;
  }
}

void solution(){
  char input[N][M];
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin >> input[i][j];
      board[i][j] = 0;
    }
  }
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if(input[i][j] == '*') BFS(i, j);
    }
  }
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if(input[i][j] == '*') cout << '*';
      else cout << board[i][j];
    }
    cout << "\n";
  }
  return;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  while(true){
    cin >> N >> M;
    if(!N and !M) break;
    solution();
  }
  return 0;
}