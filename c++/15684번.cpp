#include <bits/stdc++.h>
using namespace std;

int N, M, H, a, b;
int ladder[31][11];
int ans = 987654321;

bool isManipulated(){
  for(int j = 1; j <= N; j++){
    int col = j;
    for(int i = 1; i <= H; i++){
      if(ladder[i][col]) col++;
      else if(ladder[i][col-1]) col--;
    }
    if(col != j) return false;
  }
  return true;
}
void dfs(int depth, int cnt){
  if(depth == cnt){
    if(isManipulated()){
      cout << depth;
      exit(0);
    }
    return;
  }

  for(int j = 1; j < N; j++){
    for(int i = 1; i <= H; i++){
      if(ladder[i][j] or ladder[i][j-1] or ladder[i][j+1]) continue;
      ladder[i][j] = 1;
      dfs(depth, cnt + 1);
      ladder[i][j] = 0;

      while(!ladder[i][j-1] and !ladder[i][j+1]) i++;
    }
  }
  return;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M >> H;
  for(int i = 0; i < M; i++){
    cin >> a >> b;
    ladder[a][b] = 1;
  }

  for(int i = 0; i < 4; i++){
    dfs(i, 0);
  }
  if(ans = 987654321) ans = -1;
  cout << ans << "\n";
  return 0;
}