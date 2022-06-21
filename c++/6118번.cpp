#include <bits/stdc++.h>
using namespace std;


int N, M;
vector<vector<int>> graph;
vector<int> ans;
int visited[20202];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  graph.resize(N+1);
  for(int i = 0; i < M; i++){
    int u, v; cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  queue<int> q;
  q.push(1); // node
  fill(visited, visited + 20202, -1); visited[1] = 0;

  while(!q.empty()){
    int cur = q.front(); q.pop();
    for(auto x : graph[cur]){
      if(visited[x] != -1) continue;
      visited[x] = visited[cur] + 1;
      q.push(x);
    }
  }
  int max_dist = *max_element(visited, visited + 20202);
  for(int i = 0; i <= N; i++){
    if(max_dist == visited[i]){
      ans.push_back(i);
    }
  }
  cout << *min_element(ans.begin(), ans.end()) << " " << max_dist << " " << ans.size();
  return 0;
}