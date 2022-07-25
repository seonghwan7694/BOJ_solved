#include <bits/stdc++.h>
using namespace std;

int N, L;
vector<int> tree[101010], ans;
int order[101010];
bool visited[101010];
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;
  for(int i = 0, u, v; i < N - 1; i++){
    cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  for(int i = 0, t; i < N; i++){
    cin >> t;
    ans.push_back(t);
    order[t] = i;
  }
  for(int i = 1; i <= N; i++){
    sort(tree[i].begin(), tree[i].end(), [](int a, int b){
      return order[a] < order[b];
    });
  }

  queue<int> q;
  q.push(1);
  visited[1] = true;
  while(!q.empty()){
    int cur = q.front(); q.pop();
    if(ans[L++] != cur){
      cout << 0 << "\n";
      return 0;
    }
    for(auto nxt : tree[cur]){
      if(!visited[nxt]){
        q.push(nxt);
        visited[nxt] = true;
      }
    }
  }
  cout << 1 << "\n";
  return 0;
}