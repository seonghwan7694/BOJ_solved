#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
bool ans = false;

void dfs(int depth, int cur){
  visited[cur] = true;
  if(depth == 4){
    ans = true;
    return;
  }
  for(int nxt : adj[cur]){
    if(ans) return;
    if(!visited[nxt]){
      dfs(depth + 1, nxt);
    }
  }
  visited[cur] = false;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N, M; cin >> N >> M;
  adj.resize(N);
  visited.resize(N);

  for(int i = 0; i < M; i++){
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for(int i = 0; i < N; i++){
    fill(visited.begin(), visited.end(), false);
    dfs(0, i);
    if(ans){
      cout << 1;
      return 0;
    }
  }
  cout << 0;
  return 0;


  return 0;
}