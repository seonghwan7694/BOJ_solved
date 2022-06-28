#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int N, M;
int d[102][102];
int u, v;


int get_distance(int a, int b){
  int dis = 0;
  for(int x = 1; x <= N; x++){
    dis += min(d[x][a], d[x][b])*2;
  }
  return dis;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  for(int i = 1; i <= N; i++){
    fill(d[i] + 1, d[i] + N + 1, INF);
    d[i][i] = 0;
  }
  while(M--){
    cin >> u >> v;
    d[u][v] = 1;
    d[v][u] = 1;
  }

  for(int k = 1; k <= N; k++){
    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= N; j++){
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  int ans_i, ans_j, min_tmp = INF;
  for(int i = 1, tmp; i <= N; i++){
    for(int j = i + 1; j <= N; j++){
      tmp = get_distance(i, j);
      if(tmp < min_tmp){
        min_tmp = tmp;
        ans_i = i;
        ans_j = j;
      }
    }
  }
  cout << ans_i << " " << ans_j << " " << min_tmp;
  return 0;
}