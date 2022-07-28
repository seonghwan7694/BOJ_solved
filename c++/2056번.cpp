#include <bits/stdc++.h>
using namespace std;
int N, in_degree[10101], dp[10101], t, cost[10101], m, v;
vector<int> graph[10101];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;
  for(int i = 1; i <= N; i++){
    cin >> t;
    cost[i] = t;
    cin >> m;
    while(m--){
      cin >> v;
      graph[i].push_back(v); // i -> v
      in_degree[v]++;
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

    for(auto nxt : graph[cur.first]){
      dp[nxt] = max(dp[nxt], cost[nxt] + cur.second);
      if(--in_degree[nxt] == 0){
        q.push({nxt, dp[nxt]});
      }
    }
  }




  cout << *max_element(dp, dp + 10101) << "\n";
  return 0;
}