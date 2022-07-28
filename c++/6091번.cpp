#include <bits/stdc++.h>
using namespace std;

int N, tmp, parent[1212];
vector<pair<int, pair<int, int>>> edges;
vector<int> adj[1212];

int Find(int u){
  if(u == parent[u]) return u;
  return parent[u] = Find(parent[u]);
}

bool Merge(int u, int v){
  u = Find(u);
  v = Find(v);
  if(u == v) return false;
  if(u > v) parent[u] = v;
  else parent[v] = u;
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;

  for(int i = 1; i <= N; i++){
    parent[i] = i;
    for(int j = i + 1; j <= N; j++){
      cin >> tmp;
      edges.push_back({tmp, {i, j}});
    }
  }

  sort(edges.begin(), edges.end());

  for(auto x : edges){
    if(Merge(x.second.first, x.second.second)){
      adj[x.second.first].push_back(x.second.second);
      adj[x.second.second].push_back(x.second.first);
    }
  }

  for(int i = 1; i <= N; i++){
    cout << adj[i].size() << " ";
    sort(adj[i].begin(), adj[i].end());
    for(int x : adj[i]){
      cout << x << " ";
    }
    cout << "\n";
  }

  return 0;
}

