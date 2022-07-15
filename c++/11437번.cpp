#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int n, parent[100001], level[100001];

int lca(int a, int b){
  // a를 더 level이 높은 정점으로 맞추기
  if(level[a] < level[b]) swap(a, b);

  // 두 정점의 level을 같게 만들기
  while(level[a] != level[b]){
    a = parent[a]; // 거슬러 올라가기
  }

  // 가르키는 정점이 같아질 때까지 거슬러 올라가기
  while(a != b){
    a = parent[a];
    b = parent[b];
  }
  return a;
}

void set_tree(int node, int parent_node){
  parent[node] = parent_node;
  level[node] = level[parent_node] + 1;

  for(auto child_node : adj[node]){
    if(child_node == parent_node) continue;
    set_tree(child_node, node);
  }
}

void init(){
  int u, v;
  cin >> n;
  for(int i = 0; i < n - 1; i++){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  init();
  set_tree(1, 0);
  int u, v, query;
  cin >> query;
  while(query--){
    cin >> u >> v;
    cout << lca(u, v) << "\n";
  }

  return 0;
}