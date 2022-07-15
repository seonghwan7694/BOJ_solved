#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
int in_order[505];
int out_order[505];
vector<int> graph[505];
bool visited[505];

int DFS(int cur){
  visited[cur] = true;
  int ret = 1;
  for(auto nxt : graph[cur]){
    if(!visited[nxt]){
      in_order[nxt]++;
      ret += DFS(nxt);
    }
  }
  return ret;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  while(M--){
    int u, v;
    cin >> u >> v; // u < v -> u -> v
    graph[u].push_back(v);
  }
  for(int i = 1; i <= N; i++){
    fill(visited, visited + 505, false);
    out_order[i] = DFS(i);
  }
  for(int i = 1; i <= N; i++){
    if(in_order[i] + out_order[i] == N) ans++;
  }
  cout << ans << "\n";
  return 0;
}