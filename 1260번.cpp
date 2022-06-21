#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
int N, M, V;
bool visited[1010];

void bfs(){
  queue<int> q;
  
  q.push(V); visited[V] = true;

  while(!q.empty()){
    int cur = q.front(); q.pop();
    cout << cur << " ";
    for(auto x : graph[cur]){
      if(visited[x]) continue;
      q.push(x); visited[x] = true;
    }
  }
  return;
}

void dfs(int cur){
  if(visited[cur]) return;
  cout << cur << " "; visited[cur] = true;
  for(auto x : graph[cur]){
    if(visited[x]) continue;
    dfs(x);
  }
  return;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M >> V;
  graph.resize(N+1);
  while(M--){
    int u, v; cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  for(int i = 1; i <= N; i++){
    sort(graph[i].begin(), graph[i].end());
  }

  fill(visited, visited + 1010, false);
  dfs(V); cout << "\n";

  fill(visited, visited + 1010, false);
  bfs(); cout << "\n";

  return 0;
}