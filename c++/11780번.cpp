#include <bits/stdc++.h>
using namespace std;

#define INF 20202020
int d[101][101];
int nxt[101][101];
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
    nxt[u][v] = v; // u -> v로 가는 최단경로를 가기 위해서는 u위치에서 v로 이동해야 한다.
  }

  for(int k = 1; k <= n; k++){
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        if(d[i][k] + d[k][j] < d[i][j]){
          d[i][j] = d[i][k] + d[k][j];
          nxt[i][j] = nxt[i][k]; // i -> j로 가는 최단경로를 가기 위해서는 i -> k를 경유해야한다.
        }
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

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      if(d[i][j] == 0 or d[i][j] == INF){
        cout << 0 << "\n";
        continue;
      }
      vector<int> path;
      int st = i;
      while(st != j){
        path.push_back(st);
        st = nxt[st][j];
      }
      path.push_back(j);
      cout << path.size() << " ";
      for(auto x : path) cout << x << " ";
      cout << "\n";
    }
  }
  return 0;
}