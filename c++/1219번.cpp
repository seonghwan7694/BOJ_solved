#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
int N, M,S,E, u,v, p, c;
vector<pair<int, int>> edge[101];
int city[101];
long long dist[101];

/*
★ 음수 사이클 판단

정점의 개수가 N인 경우, 최단 경로의 크기는 최대 |N| - 1 이 됩니다.

ex) 정점의 개수 = 4, 최단 경로는 최대 3의 크기를 가짐.

즉, 사이클을 순환하여 최단 경로 크기가 커지는 것을 제한.

*/
int bfs(int S, int E){
  if(S == E) return 1;
  int visited[101] = {false};
  queue<int> q;
  q.push(S);
  visited[S] = 1;
  while(!q.empty()){
    int cur = q.front(); q.pop();
    for(auto x : edge[cur]){
      int nxt = x.second;
      if(visited[nxt]) continue;
      visited[nxt] = 1;
      if(nxt == E) return 1;
      q.push(nxt);
    }
  }
  return 0;
}

int bellan(int S, int isCycle){
  dist[S] = city[S];
  for(int j = 0; j < N - 1 + isCycle; j++){
    for(int k = 0; k < N; k++){
      if(dist[k] == -INF) continue;
      for(int i = 0; i < edge[k].size(); i++){
        int nxt_node = edge[k][i].second;
        int nxt_cost = edge[k][i].first;
        if(dist[nxt_node] >= dist[k] + nxt_cost + city[nxt_node]) continue;
        dist[nxt_node] = dist[k] + nxt_cost + city[nxt_node];
        if(j == N - 1){
          if(bfs(nxt_node, E)) return nxt_node;
        }
      }
    }
  }
  return -1;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> S >> E >> M;
  edge->clear();
  for(int i = 0; i < M; i++){
    cin >> u >> v >> p;
    edge[u].push_back({-p, v});
  }
  for(int i = 0; i < N; i++){
    cin >> city[i];
  }
  fill_n(dist, sizeof(dist)/sizeof(long long), -INF);
  int isInf = bellan(S, 1);

  if(dist[E] == -INF){
    cout << "gg" << "\n";
  }else if(isInf != -1){
    cout << "Gee" << "\n";
  }else{
    cout << dist[E] << "\n";
  }

  return 0;
}