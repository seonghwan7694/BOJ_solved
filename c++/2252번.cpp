#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> in_degree;
vector<vector<int>> graph;


int main(){
  ios::sync_with_stdio(false);
  cout.tie(0); cin.tie(0);

  cin >> N >> M;
  graph.resize(N + 1);
  in_degree.resize(N + 1);

  while(M--){
    int u, v; cin >> u >> v; // u -> v
    graph[u].push_back(v);
    in_degree[v]++;
  }

  queue<int> q;
  for(int i = 1; i <= N; i++){
    if(in_degree[i] == 0) q.push(i);
  }

  while(!q.empty()){
    int cur = q.front();
    q.pop();

    cout << cur << " ";
    for(auto x : graph[cur]){
      in_degree[x]--;
      if(!in_degree[x]) q.push(x);
    }
  }
  return 0;
}