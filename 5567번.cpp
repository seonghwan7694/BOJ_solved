#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
vector<int> graph[505];
bool visited[505];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  while(M--){
    int u, v; cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  queue<pair<int, int>> q;
  q.push({1, 0}); visited[1] = true;

  while(!q.empty()){
    auto cur = q.front(); q.pop();
    if(cur.second <= 2) ans++;
    for(auto x : graph[cur.first]){
      if(visited[x]) continue;
      q.push({x, cur.second + 1});
      visited[x] = true;
    }
  }
  cout << ans - 1 << "\n";
  return 0;
}