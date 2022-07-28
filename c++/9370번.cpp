#include <bits/stdc++.h>
using namespace std;

int T, n, m, t, a, b, d, x, s, g, h;
const int INF = 1e9 + 7;

void dijkstra(int start, vector<pair<int, int>> graph[], int d[]){
  priority_queue<pair<int, int>> pq;
  pq.push({0, start});
  d[start] = 0;
  while(!pq.empty()){
    int dist = -pq.top().first;
    int now = pq.top().second;
    pq.pop();

    if(d[now] < dist) continue;
    for(int i = 0; i < graph[now].size(); i++){
      int cost = dist + graph[now][i].second;
      if(cost < d[graph[now][i].first]){
        d[graph[now][i].first] = cost;
        pq.push({-cost, graph[now][i].first});
      }
    }
  }
}

void solution(){
  vector<pair<int, int>> graph[2020];
  vector<int> ans;
  int dist1[2020], dist2[2020], dist3[2020];
  fill(dist1, dist1 + 2020, INF); // s-dijkstra
  fill(dist2, dist2 + 2020, INF); // g-dijkstra
  fill(dist3, dist3 + 2020, INF); // h-dijkstra

  cin >> n >> m >> t; // n : 교차로 개수, m : 도로 개수, t : 목적지 후보의 개수
  cin >> s >> g >> h; // s : 예술가들의 출발지, g - h : (정답이려면) 반드시 지나가는 간선
  for(int i = 0; i < m; i++){
    cin >> a >> b >> d; // a, b 사이에 길이 d의 양방향 도로
    graph[a].push_back({b, d});
    graph[b].push_back({a, d});
  }
  for(int i = 0; i < t; i++){
    cin >> x; // x : 목적지 후보
    ans.push_back(x);
  }

  dijkstra(s, graph, dist1);
  dijkstra(g, graph, dist2);
  dijkstra(h, graph, dist3);

  sort(ans.begin(), ans.end());
  for(auto x : ans){
    if(dist1[x] == dist1[g] + dist2[h] + dist3[x]){ // s -> dst 가 s -> g -> h -> dst 와 같다면,
      cout << x << " ";
      continue;
    }
    if(dist1[x] == dist1[h] + dist3[g] + dist2[x]){ // s -> dst 가 s -> h -> g -> dst 와 같다면,
      cout << x << " ";
      continue;
    }
  }
  cout << "\n";
  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> T;
  while(T--){
    solution();
  }


  return 0;
}