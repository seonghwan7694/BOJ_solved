#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
vector<vector<int>> graph;
bool visited[1001];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  graph.resize(N+1);
  while(M--){
    int u, v; cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  queue<int> q;
  for(int u = 1; u <= N; u++){
    if(visited[u]) continue;
    ans++; q.push(u); visited[u] = true;
    while(!q.empty()){
      int cur = q.front(); q.pop();
      for(auto x : graph[cur]){
        if(visited[x]) continue;
        q.push(x); visited[x] = true;
      }
    }
  }
  cout << ans << "\n";

  return 0;
}