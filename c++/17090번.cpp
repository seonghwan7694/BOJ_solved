#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[505][505];
bool vis[505][505];
int ans[505][505];

int DFS(int x, int y){
  if(x < 0 or x >= N or y < 0 or y >= M){
    return 1;
  }else if(ans[x][y] == 1){
    return 1;
  }else if(vis[x][y] == true){
    return 0;
  }
  vis[x][y] = true;

  switch(board[x][y]){
    case 'U':
      return ans[x][y] = DFS(x-1, y);
      break;
    case 'R':
      return ans[x][y] = DFS(x, y+1);
      break;
    case 'D':
      return ans[x][y] = DFS(x+1, y);
      break;
    case 'L':
      return ans[x][y] = DFS(x, y-1);
      break;

  }
  return -1;
} 
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  for(int i = 0; i < N; i++){
    string str;
    cin >> str;
    for(int j = 0; j < M; j++){
      board[i][j] = str[j];
    }
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if(ans[i][j] == 0) DFS(i, j);
    }
  }

  int res = 0;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if(ans[i][j] == 1) res++;
    }
  }
  cout << res << "\n";
  return 0;
}