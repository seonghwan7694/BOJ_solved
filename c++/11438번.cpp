#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[100001];
int parent[100001][18];        //parent[i][j] : i번 노드의 2^j번째 조상
int level[100001], maxlevel;

void set_tree(int node, int pnode, int lv){
  level[node] = lv;
  parent[node][0] = pnode;

  for(int i = 1; i <= maxlevel; i++){
    parent[node][i] = parent[parent[node][i - 1]][i - 1];
  }

  for(int i = 0; i < adj[node].size(); i++){
    int childnode = adj[node][i];
    if(childnode == pnode) continue;
    set_tree(childnode, node, lv + 1);
  }
}

int LCA(int a, int b){
  if(a == 1 or b == 1) return 1;

  int target = a, compare = b;
  if(level[a] < level[b]) swap(target, compare);

  if(level[target] != level[compare]){
    for(int i = maxlevel; i >= 0; i--){
      if(level[parent[target][i]] >= level[compare]) target = parent[target][i];
    }
  }

  int ret = target;
  if(target != compare){
    for(int i = maxlevel; i >= 0; i--){
      if(parent[target][i] != parent[compare][i]){
        target = parent[target][i];
        compare = parent[compare][i];
      }
      ret = parent[target][i];
    }
  }
  return ret;
}

void init(){
  cin >> n;
  for(int i = 0, u, v; i < n - 1; i++){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  init();
  maxlevel = (int)floor(log2(100001));
  set_tree(1, 0, 1);

  cin >> m;
  int u, v;
  while(m--){
    cin >> u >> v;
    cout << LCA(u , v) << "\n";
  }

  return 0;
}