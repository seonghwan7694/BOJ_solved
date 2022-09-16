#include <bits/stdc++.h>
using namespace std;
int N, M, ans = 1;
int dx[3] = {1, 1, 0};
int dy[3] = {0, 1, 1};

void BFS(vector<string>& board, int x, int y){
  int tmp_ans = 1;
  int w = 1;
  while(true){
    int nx_0 = x + dx[0]*w; int ny_0 = y + dy[0]*w;
    int nx_1 = x + dx[1]*w; int ny_1 = y + dy[1]*w;
    int nx_2 = x + dx[2]*w; int ny_2 = y + dy[2]*w;
    if(nx_1 >= N or ny_1 >= M) break;
    if(board[x][y] == board[nx_0][ny_0] and board[nx_0][ny_0] == board[nx_1][ny_1] and board[nx_1][ny_1] == board[nx_2][ny_2]){
      tmp_ans = w + 1;
      ans = max(ans, tmp_ans * tmp_ans);
    }
    w++;
  }
  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;
  vector<string> board(N);

  for(int i = 0; i < N; i++){
    cin >> board[i];
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      BFS(board, i, j);
    }
  }
  cout << ans << '\n';
  return 0;
}