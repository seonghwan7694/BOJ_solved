#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 1010101
// dp[v][0] = {v를 루트로 하는 서브트리에서 v가 얼리 어답터가 아닐 때, 필요한 얼리 아답터의 최소값}
// dp[v][1] = {v를 루트로 하는 서브트리에서 v가 얼리 어답터일 때, 필요한 얼리 아답터의 최소값}
int N, dp[MAX_SIZE][2];
vector<int> g[MAX_SIZE];
bool vis[MAX_SIZE];

void func(int r){
  vis[r] = true;
  dp[r][1] = 1;
  
  for(auto c : g[r]){
    if(vis[c]) continue;
    func(c);
    dp[r][1] += min(dp[c][0], dp[c][1]);
    dp[r][0] += dp[c][1];
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for(int i = 1, u, v; i < N; i++){
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  func(1);
  cout << min(dp[1][0], dp[1][1]) << "\n";
}