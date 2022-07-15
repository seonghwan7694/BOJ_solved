#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int tc, n, k, c;

pair<int, int> solution(int start){
  vector<pair<int, int>> adj[10101];
  bool visited[10101] = {false};
  int d[10101]; fill(d, d+ 10101, INF);
  int cnt = 0;

  while(k--){
    int a, b, s;
    cin >> a >> b >> s; // b -> a
    // 컴퓨터 a가 컴퓨터 b를 의존하며, 컴퓨터 b가 감염되면 s초 후 컴퓨터 a도 감염된다
    adj[b].push_back({a, s});
  } 

  priority_queue<pair<int, int>> pq;
  pq.push({0, start}); d[start] = 0;

  while(!pq.empty()){
    int dist = -pq.top().first;
    int now = pq.top().second;
    pq.pop();

    if(!visited[now]){
      visited[now] = true;
      cnt++;
    }
    if(d[now] < dist) continue;

    for(int i = 0; i < adj[now].size(); i++){
      int cost = dist + adj[now][i].second;
      if(cost < d[adj[now][i].first]){
        d[adj[now][i].first] = cost;
        pq.push({-cost, adj[now][i].first});
      }
    }
  }
  int max_dist = 0;
  for(int i = 0; i < 10101; i++){
    if(d[i] == INF) continue;
    max_dist = max(d[i], max_dist);
  }
  return {cnt, max_dist};
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> tc;
  while(tc--){
    cin >> n >> k >> c; // n : 컴퓨터 개수, d : 의존성 개수, c : 해킹 시작점
    auto ans = solution(c);
    cout << ans.first << " " << ans.second << "\n";
  }

  return 0;
}