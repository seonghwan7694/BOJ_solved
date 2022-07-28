#include <bits/stdc++.h>
using namespace std;

int N, t, s, in_degree[505], dp[505], cost[505]; // dp[i] = cost : i번 건물을 짓는데 걸리는 최대 시간
vector<int> graph[505];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;
  for(int i = 1; i <= N; i++){
    cin >> t;
    cost[i] = t;
    while(true){
    cin >> s;
    if(s == -1) break;
    graph[s].push_back(i); // s -> i
    in_degree[i]++;
    }
  }

  queue<pair<int, int>> q; // {node_idx, cost}
  for(int i = 1; i <= N; i++){
    if(in_degree[i] == 0){
      q.push({i, cost[i]});
      dp[i] = cost[i];
    }
  }

  while(!q.empty()){
    auto cur = q.front();
    q.pop();

    for(auto nxt : graph[cur.first]){ // cur.first -> nxt
      dp[nxt] = max(dp[nxt], cost[nxt] + cur.second);
      if(--in_degree[nxt] == 0){
        q.push({nxt, dp[nxt]});
      }
    }
  }
  for(int i = 1; i <= N; i++){
    cout << dp[i] << "\n";
  }
  return 0;
}