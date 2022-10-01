#include <bits/stdc++.h>
using namespace std;

long long N, arr[101], dp[100][21];

long long DFS(int n, int tmp){
  if(n == N - 1){
    if(tmp == arr[N - 1]) return 1;
    return 0;
  }
  auto& ret = dp[n][tmp];
  if(ret != -1) return ret;
  ret = 0;
  if(tmp + arr[n] <= 20) ret += DFS(n + 1, tmp + arr[n]);
  if(tmp - arr[n] >= 0) ret += DFS(n + 1, tmp - arr[n]);
  return ret;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> arr[i];
    for(int j = 0; j < 21; j++){
      dp[i][j] = -1;
    }
  }

  cout << DFS(1, arr[0]);
  return 0;
}