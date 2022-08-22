#include <bits/stdc++.h>
using namespace std;

void solution(){
  int dp[501][501] = {0};
  int cost[501] = {0};
  int sum[501] = {0};
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> cost[i];
    sum[i] = sum[i-1] + cost[i];
  }

  for(int d = 1; d < n; d++){
    for(int tx = 1; tx + d <= n; tx++){
      int ty = tx + d;
      dp[tx][ty] = 1e9 + 7;
      for(int mid = tx; mid < ty; mid++){
        dp[tx][ty] = min(dp[tx][ty], dp[tx][mid] + dp[mid + 1][ty] + sum[ty] - sum[tx - 1]);
      }
    }
  }
  cout << dp[1][n] << "\n";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int t;
  cin >> t;
  while(t--){
    solution();
  }


  return 0;
}