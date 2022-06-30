#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int V, E;
int u, v, c, a, b;
vector<pair<int, int>> graph[808];
int d[808];

int dijkstra(int start, int end){
  fill(d, d + 808, INF);
  priority_queue<pair<int, int>> pq;
  pq.push({0, start}); d[start] = 0;
  
  while(!pq.empty()){
    int dist = -pq.top().first;
    int now = pq.top().second;
    pq.pop();

    if(d[now] < dist) continue;

    for(auto x : graph[now]){
      int cost = dist + x.second;
      if(cost < d[x.first]){
        d[x.first] = cost;
        pq.push({-cost, x.first});
      }
    }
  }
  if(d[end] == INF){
    cout << -1 << "\n";
    exit(0);
  }
  return d[end];
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> V >> E;
  while(E--){
    cin >> u >> v >> c;
    graph[u].push_back({v, c});
    graph[v].push_back({u, c});
  }
  cin >> a >> b;
  cout << min(dijkstra(1, a) + dijkstra(a, b) + dijkstra(b, V), dijkstra(1, b) + dijkstra(b, a) + dijkstra(a, V));
  return 0;
}