#include <bits/stdc++.h>
using namespace std;

#define MAX 1000001
int N, Memo[MAX][2];
vector<bool> visited;
vector<int> v[MAX];
vector<int> tree[MAX];

void input(){
  cin >> N;
  for(int i = 0; i < N - 1; i++){
    int a, b; cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  visited.resize(MAX, false);
}

void make_tree(int cur){
  visited[cur] = true;
  for(int nxt : v[cur]){
    if(!visited[nxt]){
      tree[cur].push_back(nxt);
      make_tree(nxt);
    }
  }
}

int DFS(int cur, int state){
  if(Memo[cur][state] != -1) return Memo[cur][state];
  if(state == 1){
    Memo[cur][state] = 1;
    for(auto nxt : tree[cur]){
      Memo[cur][state] += min(DFS(nxt, 0), DFS(nxt, 1));
    }
  }else{
    Memo[cur][state] = 0;
    for(auto nxt : tree[cur]){
      Memo[cur][state] += DFS(nxt, 1);
    }
  }
  return Memo[cur][state];
}
void solution(){
  make_tree(1);
  memset(Memo, -1, sizeof(Memo));
  cout << min(DFS(1, 0), DFS(1, 1)) << "\n";
}
void solve(){
  input();
  solution();
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  solve();




  return 0;
}