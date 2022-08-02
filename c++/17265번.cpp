#include <bits/stdc++.h>
using namespace std;

int N;
char board[8][8];
const int INF = 987654321;
pair<int, int> value[8][8]; // {min, max}
int dx[2] = {1, 0};
int dy[2] = {0, 1};
void DFS(int x, int y){

  for(int i = 0; i < 2; i++){
    int op_x = x + dx[i];
    int op_y = y + dy[i];

    for(int j = 0; j < 2; j++){
      int num_x = op_x + dx[j];
      int num_y = op_y + dy[j];

      if(num_x < 0 or num_x >= N or num_y < 0 or num_y >= N) continue;

      switch (board[op_x][op_y])
      {
      case '+':
        value[num_x][num_y].first = min({value[num_x][num_y].first, value[x][y].first + board[num_x][num_y], value[x][y].second + board[num_x][num_y]});
        value[num_x][num_y].second = max({value[num_x][num_y].second, value[x][y].first + board[num_x][num_y], value[x][y].second + board[num_x][num_y]});
        DFS(num_x, num_y);
        break;
      case '-':
        value[num_x][num_y].first = min({value[num_x][num_y].first, value[x][y].first - board[num_x][num_y], value[x][y].second - board[num_x][num_y]});
        value[num_x][num_y].second = max({value[num_x][num_y].second, value[x][y].first - board[num_x][num_y], value[x][y].second - board[num_x][num_y]});
        DFS(num_x, num_y);
        break;
      case '*':
        value[num_x][num_y].first = min({value[num_x][num_y].first, value[x][y].first * board[num_x][num_y], value[x][y].second * board[num_x][num_y]});
        value[num_x][num_y].second = max({value[num_x][num_y].second, value[x][y].first * board[num_x][num_y], value[x][y].second * board[num_x][num_y]});
        DFS(num_x, num_y);
        break;
      }

    }
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> board[i][j];
      if((i + j)% 2 == 0) board[i][j] -= '0';
      value[i][j] = {INF, -INF}; // {min, max}
    }
  }

  value[0][0] = {board[0][0], board[0][0]};
  DFS(0, 0);
  cout << value[N-1][N-1].second << " " << value[N-1][N-1].first << "\n";
  return 0;
}