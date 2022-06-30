#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int V, E, u, v, c, st, en;
vector<pair<int, int>> graph[1010];
vector<int> ans;
int d[1010];
int route[1010];


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> V >> E;
  while(E--){
    cin >> u >> v >> c;
    graph[u].push_back({v, c});
  } cin >> st >> en;

  fill(d, d + 1010, INF);
  priority_queue<pair<int, int>> pq;
  pq.push({0, st}); d[st] = 0;
  while(!pq.empty()){
    int cost = -pq.top().first;
    int now = pq.top().second;
    pq.pop();
    if(now == en) break;
    for(auto x : graph[now]){
      int nxt = x.first;
      int nxt_cost = x.second;
      if(d[nxt] > d[now] + nxt_cost){
        d[nxt] = d[now] + nxt_cost;
        route[nxt] = now;
        pq.push({-d[nxt], nxt});
      }
    }
  }
  cout << d[en] << "\n";
  int idx = en;
  while(idx != st){
    ans.push_back(idx);
    idx = route[idx];
  }
  ans.push_back(idx);
  reverse(ans.begin(), ans.end());
  cout << ans.size() << "\n";
  for(auto x : ans) cout << x << " ";
  return 0;
}