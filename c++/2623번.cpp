#include <bits/stdc++.h>
using namespace std;

int N, M, u, v, tmp, line; // N : 가수의 수, M : 보조 PD의 수
vector<int> graph[1010];
int in_degree[1010];
vector<int> ans;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  while(M--){
    cin >> line >> u >> v;
    graph[u].push_back(v); // u - > v;
    in_degree[v]++; line -= 2;
    tmp = v;
    while(line--){ // [0, line - 2]
      cin >> v;
      graph[tmp].push_back(v); in_degree[v]++; // tmp -> v
      tmp = v;
    }
  }

  queue<int> q;
  for(int i = 1; i <= N; i++){
    if(!in_degree[i]){
      q.push(i);
      ans.push_back(i);
    }
  } 
  while(!q.empty()){
    int cur = q.front(); q.pop();
    for(int x : graph[cur]){
      in_degree[x]--;
      if(!in_degree[x]){
        q.push(x);
        ans.push_back(x);
      }
    }
  }
  if(ans.size() != N){
    cout << 0 << "\n";
    return 0;
  }else{
    for(auto x : ans){
      cout << x << "\n";
    }
    return 0;
  }
  return 0;
}