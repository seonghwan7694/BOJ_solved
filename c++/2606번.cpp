#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
bool visited[101];
int N, M;
int ans;
void dfs(int cur){
  if(visited[cur]) return;
  visited[cur] = true; ans++;
  for(auto x : adj[cur]){
    dfs(x);
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  // 1번 정점이 시작 정점

  cin >> N >> M;
  adj.resize(N+1);
  while(M--){
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1);

  cout << ans - 1 << "\n"; // 자기자신은 제외
  return 0;
}