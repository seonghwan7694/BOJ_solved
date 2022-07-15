#include <bits/stdc++.h>
using namespace std;

long long a[404][404];
bool visited[404];
const long long INF = 9876543210;
long long V, E, res = INF;

void floyd(){
  for(int k = 1; k <= V; k++){
    for(int i = 1; i <= V; i++){
      for(int j = 1; j <= V; j++){
        if(a[i][j] > a[i][k] + a[k][j]){
          a[i][j] = a[i][k] + a[k][j];
          if(i == j) res = min(res, a[i][i]);
        }
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> V >> E;
  for(int i = 1; i <= V; i++){
    fill(a[i] + 1, a[i] + V + 1, INF);
  }
  while(E--){
    int u, v, c;
    cin >> u >> v >> c; // u -> v
    a[u][v] = c;
  }
  floyd();
  if(res == INF){
    cout << -1 << "\n";
  }else cout << res << "\n";
  
  return 0;
}