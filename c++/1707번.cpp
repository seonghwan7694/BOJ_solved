#include <bits/stdc++.h>
using namespace std;
/*test*/
void solution(){
  int V, E; cin >> V >> E;
  int color[20202] = {0};
  vector<vector<int>> graph;
  graph.resize(V+1);

  while(E--){
    int u, v; cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  for(int v = 1; v <= V; v++){
    if(!color[v]){ // 색깔이 정해지지 않았다면
      color[v] = 1; // 색깔을 칠해주고 BFS를 돈다.
      queue<int> q; q.push(v);
      while(!q.empty()){
        auto cur = q.front(); q.pop();

        for(auto x : graph[cur]){
          if(color[x] == color[cur]){
            cout << "NO" << "\n";
            return;
          }
          if(color[x] != 0) continue; // 색상이 정해졌다면, 위로위로!
          color[x] = color[cur] * -1;
          q.push(x);
        }
      }
    }
  }
  cout << "YES" << "\n";
  return;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int tc; cin >> tc;
  while(tc--){
    solution();
  }
  return 0;
}
