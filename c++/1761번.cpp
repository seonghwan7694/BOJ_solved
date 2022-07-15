#include <bits/stdc++.h>
using namespace std;

const int MAX = 40001;
int V, Q;

vector<pair<int, int>> adj[MAX];
bool visited[MAX];

int length[MAX][16];
int parent[MAX][16];
int depth[MAX];

void Input(){
  cin >> V;
  for(int i = 0, u, v, c; i < V - 1; i++){
    cin >> u >> v >> c;
    adj[u].push_back({v, c});
    adj[v].push_back({u, c});
  }
}

void connect(){
  for(int p = 1; p < 16; p++){
    for(int cur = 1; cur <= V; cur++){
      int prevParent = parent[cur][p - 1];
      parent[cur][p] = parent[prevParent][p - 1];
      if(!parent[prevParent][p - 1]) continue;
      int prevLength = length[cur][p - 1];
      length[cur][p] = prevLength + length[prevParent][p -1];
    }
  }
}

int LCA(int u, int v){
  if(depth[u] > depth[v]) swap(u, v); // v 가 더 깊은 노드
  int lenSum = 0;
  for(int i = 15; i >= 0; i--){
    int jump = 1 << i;
    if(depth[v] - depth[u] >= jump){
      lenSum += length[v][i];
      v = parent[v][i];
    }
  }
  if(u == v) return lenSum;
  for(int i = 15; i >= 0; i--){
    if(parent[u][i] == parent[v][i]) continue;
    lenSum += length[u][i];
    u = parent[u][i];

    lenSum += length[v][i];
    v = parent[v][i];
  }
  lenSum += length[u][0] + length[v][0];
  return lenSum;
}

void Make_tree(int cur, int level){
  visited[cur] = true;
  depth[cur] = level;
  for(auto nxt : adj[cur]){
    if(visited[nxt.first]) continue;
    parent[nxt.first][0] = cur;
    length[nxt.first][0] = nxt.second;
    Make_tree(nxt.first, level + 1);
  }
}


void Solution(){
  Make_tree(1, 0);
  connect();
  cin >> Q;
  while(Q--){
    int u, v;
    cin >> u >> v;
    cout << LCA(u ,v) << "\n";
  }
}
void Solve(){
  Input();
  Solution();
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  Solve();
  return 0;
}