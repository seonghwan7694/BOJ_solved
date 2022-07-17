#include <bits/stdc++.h>
using namespace std;

int tc, N;

void solution(){
  int dp[101010][2] = {0};
  int sticker[101010][2] = {0};

  cin >> N;
  for(int k = 0; k < 2; k++) for(int i = 0; i < N; i++){
    cin >> sticker[i][k];
  }
  dp[0][0] = sticker[0][0];
  dp[0][1] = sticker[0][1];

  dp[1][0] = max(dp[0][1] + sticker[1][0], dp[0][0]);
  for(int i = 1; i < N; i++){
    dp[i][0] = max(dp[i-1][1] + sticker[i][0], dp[i-1][0]);
    dp[i][1] = max(dp[i-1][0] + sticker[i][1], dp[i-1][1]);
  }
  cout << max(dp[N-1][0], dp[N-1][1]) << "\n";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> tc;
  while(tc--){
    solution();
  }
  return 0;
}