#include <bits/stdc++.h>
using namespace std;

#define INF 20202020
int d[101][101];
int n, m;
int u, v, cost;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for(int i = 1; i <= n; i++){
    fill(d[i] + 1, d[i] + n + 1, INF);
    d[i][i] = 0;
  }

  cin >> m;
  while(m--){
    cin >> u >> v >> cost;
    d[u][v] = min(d[u][v], cost);
  }

  for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(d[i][j] == INF) cout << 0 << " ";
      else cout << d[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}