#include <bits/stdc++.h>
using namespace std;
#define INF 101010
int N, M, K;
int u, v, t;
int d[202][202];
int ans[202];
vector<int> house;

void input(){
  cin >> N >> M;
  for(int i = 1; i <= N; i++){
    fill(d[i] + 1, d[i] + N + 1, INF);
    d[i][i] = 0;
  }
  while(M--){
    cin >> u >> v >> t;
    d[u][v] = min(d[u][v], t);
  }
  cin >> K;
  house.resize(K);
  for(int i = 0; i < K; i++){
    cin >> house[i];
  }
}

void floyd(){
  for(int k = 1; k <= N; k++){
    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= N; j++){
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

void solution(){
  vector<int> ans;
  int res = INF;
  for(int x = 1; x <= N; x++){
    int tmp = 0;
    bool flag = false;
    for(auto st : house){
      if(d[st][x] == INF or d[x][st] == INF){
        flag = true;
        break;
      }
      tmp = max(tmp, d[st][x] + d[x][st]);
    }
    if(flag) continue;
    if(res > tmp){
      res = tmp;
      ans.clear();
      ans.push_back(x);
    }else if(res == tmp){
      ans.push_back(x);
    }
  }
  sort(ans.begin(), ans.end());
  for(auto x : ans) cout << x << " ";
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  input();
  floyd();
  solution();
  return 0;
}