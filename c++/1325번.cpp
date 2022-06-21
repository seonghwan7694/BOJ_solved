#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> graph[10101];
int ans[10101];

// 5초니까 가능하지 않을까?

int bfs(int cur){
  bool visited[10101] = {0};
  queue<int> q;

  int can_hacking = 1; // 자기 자신은 항상 해킹할 수 있다.
  q.push(cur); visited[cur] = true;

  while(!q.empty()){
    auto cur = q.front(); q.pop();
    for(auto x : graph[cur]){
      if(visited[x]) continue;
      q.push(x); visited[x] = true; can_hacking++;
    }
  }
  return can_hacking;
}
int main(){
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  cin >> N >> M;
  while(M--){
    int u, v; cin >> u >> v;
    graph[v].push_back(u); // u가 v를 신뢰한다. === v로 u를 해킹할 수 있다.
  }

  for(int u = 1; u <= N; u++){
    ans[u] = bfs(u);
  }
  int tmp = *max_element(ans + 1, ans + 1 + N); // [1, N + 1)
  for(int u = 1; u <= N; u++){
    if(ans[u] == tmp) cout << u << " ";
  }
  return 0;
}