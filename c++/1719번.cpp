#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int board[202][202];
int ans[202][202];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n, m;
  cin >> n >> m;
  
  for(int i = 1; i <= n; i++){
    fill(board[i] + 1, board[i] + n + 1, INF);
  }
  while(m--){
    int u, v, c;
    cin >> u >> v >> c;
    board[u][v] = c, board[v][u] = c; // u -> v, v -> u 가는데 시간 c 걸린다.
    ans[u][v] = v, ans[v][u] = u; // u 에서 v 집하장으로 최단 경로를 통해 가기 위해서는 v를 들려야한다.
  }

  for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        if(board[i][k] + board[k][j] < board[i][j]){
          board[i][j] = board[i][k] + board[k][j];
          ans[i][j] = ans[i][k];
        }
      }
    }
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(i == j){
        cout << "- ";
        continue;
      }
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}