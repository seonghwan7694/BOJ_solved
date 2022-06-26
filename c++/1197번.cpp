#include <bits/stdc++.h>
using namespace std;

int parent[10101];
bool check;
int V, E, A, B, C;
long long ans;
vector<tuple<int, int, int>> graph;

int Find(int x){
  if(parent[x] == x) return x;
  return parent[x] = Find(parent[x]);
}

void Union(int u, int v){
  check = false;
  u = Find(u);
  v = Find(v);

  if(u == v){
    return;
  }else{
    parent[u] = v;
    check = true;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> V >> E;

  for(int i = 1; i <= V; i++){
    parent[i] = i;
  }

  for(int i = 0; i < E; i++){
    cin >> A >> B >> C;
    graph.push_back(make_tuple(C, A, B));
  }

  sort(graph.begin(), graph.end());
  for(int i = 0; i < E; i++){
    Union(get<1>(graph[i]), get<2>(graph[i]));
    if(check) ans += get<0>(graph[i]);
  }
  cout << ans;
  return 0;
}