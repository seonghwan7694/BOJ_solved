#include <bits/stdc++.h>
using namespace std;

int N, M, cnt;
vector<int> graph[100];
int ans[100];
int in_degree[100]; // in_degree[n] = cnt : n번 노드보다 가벼운 노드의 개수 cnt
int out_degree[100]; // out_degree[n] = cnt : n번 노드보다 무거운 노드의 개수 cnt
// 무게가 중간이 절대로 될 수 없는, (N+1)/2보다 차수가 높은 구슬의 수를 출력 한다.

void bfs(int node){
  bool visited[100] = {0};
  int out = 0;
  queue<int> q;
  
  q.push(node); visited[node] = true;

  while(!q.empty()){
    auto cur = q.front(); q.pop();
    for(auto x : graph[cur]){
      if(visited[x]) continue;
      out++; in_degree[x]++;
      visited[x] = true;
      q.push(x);
    }
  }
  out_degree[node] = out;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  int mid = (N+1)/2;
  while(M--){
    int u, v; cin >> u >> v; // u가 v보다 무겁다.
    graph[v].push_back(u);
  }

  for(int n = 1; n <= N; n++){
    bfs(n);
  }
  for(int n = 1; n <= N; n++){
    if(in_degree[n] >= mid or out_degree[n] >= mid) cnt++;
  }
  cout << cnt << "\n";
  return 0;
}