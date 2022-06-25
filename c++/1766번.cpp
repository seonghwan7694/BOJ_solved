#include <bits/stdc++.h>
using namespace std;

int N, M, u, v;
vector<int> graph[33333], ans, tmp;
int in_degree[33333];
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  while(M--){
    cin >> u >> v; // u -> v
    graph[u].push_back(v);
    in_degree[v]++;
  }

  for(int i = 1; i <= N; i++){
    if(!in_degree[i]) pq.push(i);
  }

  while(!pq.empty()){
    int cur = pq.top();
    pq.pop();
    cout << cur << " ";
    for(auto x : graph[cur]){
      if(--in_degree[x] == 0){
        pq.push(x);
      }
    }
  }
  return 0;
}
      