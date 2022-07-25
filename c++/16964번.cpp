#include <bits/stdc++.h>
using namespace std;

int n, idx;
vector<int> tree[101010];
vector<int> ans;
bool check[101010];
int path[101010];
int order[101010];
bool compare(int a, int b){
  return order[a] < order[b];
}
void dfs(int x){
  check[x] = true;
  path[idx++] = x;
  for(auto nxt : tree[x]){
    if(!check[nxt]){
      dfs(nxt);
    }
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for(int i = 0, u, v; i < n - 1; i++){
    cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  for(int i = 0, t; i < n; i++){
    cin >> t;
    ans.push_back(t);
    order[t] = i;
  }
  for(int i = 1; i <= n; i++){
    sort(tree[i].begin(), tree[i].end(), compare);
  }
  dfs(1);
  for(int i = 0; i < n; i++){
    if(ans[i] != path[i]){
      cout << 0 << "\n";
      return 0;
    }
  }
  cout << 1 << "\n";
  return 0;
}