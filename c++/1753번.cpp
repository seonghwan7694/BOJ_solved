#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int V, E, u, v, w, st;
vector<pair<int, int>> graph[20202];
int d[20202];

void dijkstra(int start){
  priority_queue<pair<int, int>> pq;
  pq.push({0, start});

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
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> V >> E >> st;
  while(E--){
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
  }

  fill(d, d + 20202, INF);

  dijkstra(st);
  d[st] = 0;
  for(int i = 1; i <= V; i++){
    if(d[i] == INF){
      cout << "INF" << "\n";
    }else cout << d[i] << "\n";
  }

  return 0;
}