#include <bits/stdc++.h>
using namespace std;
#define INF 202020

int n, m, r;
int u, v, cost;
int d[101][101];
int item[101];
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> n >> m >> r;
  
  for(int i = 1, tmp; i <= n; i++){
    cin >> tmp;
    item[i] = tmp;
    fill(d[i] + 1, d[i] + n + 1, INF);
    d[i][i] = 0;
  }
  while(r--){
    cin >> u >> v >> cost;
    d[u][v] = min(cost, d[u][v]);
    d[v][u] = min(cost, d[v][u]);
  }

  for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  int res = 0;
  for(int i = 1; i <= n; i++){
    int tmp_res = 0;
    for(int j = 1; j <= n; j++){
      if(d[i][j] <= m) tmp_res += item[j];
    }
    res = max(res, tmp_res);
  }
  cout << res << "\n";
  return 0;
}