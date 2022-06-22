#include <bits/stdc++.h>
using namespace std;

int N;
int parent[101010];
vector<int> graph[101010];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;
  for(int i = 1; i < N; i++){ // [1, N) -> N - 1번 실행
    int u, v; cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  queue<int> q;
  q.push(1);
  while(!q.empty()){
    auto cur = q.front(); q.pop();
    for(auto x : graph[cur]){
      if(parent[x]) continue;
      parent[x] = cur;
      q.push(x);
    }
  }

  for(int i = 2; i <= N; i++){
    cout << parent[i] << "\n";
  }
  return 0;
}