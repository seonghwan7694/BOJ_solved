#include <bits/stdc++.h>
using namespace std;

vector<int> graph[51];
bool visited[51];
int ans[51];
vector<int> v; // 회장 정보 담는 벡터
int N;


int bfs(int node){
  queue<pair<int, int>> q;
  int max_dist = 0;
  visited[node] = true; q.push({node, 0}); 

  while(!q.empty()){
    auto cur = q.front(); q.pop();
    max_dist = max(max_dist, cur.second);

    for(auto x : graph[cur.first]){
      if(visited[x]) continue;
      visited[x] = true; q.push({x, cur.second + 1});
    }

  }
  return max_dist;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;

  while(true){
    int u, v; cin >> u >> v;
    if(u == -1 and v == -1) break;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  
  for(int u = 1; u <= N; u++){
    fill(visited, visited + 51, false);
    ans[u] = bfs(u);
  }

  int tmp = *min_element(ans + 1, ans + N + 1); // [1, N + 1)
  for(int u = 1; u <= N; u++){
    if(ans[u] == tmp) v.push_back(u);
  }
  cout << ans[v.front()] << " " << v.size() << "\n";
  for(auto x : v) cout << x << " ";
  return 0;
}