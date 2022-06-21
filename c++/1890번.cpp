#include <bits/stdc++.h>
using namespace std;

int N;
long long MAP[101][101];
long long dp[101][101]; // dp[i][j] = val : dp[0][0]에서 dp[i][j]까지 갈 수 있는 경우의 수
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

 cin >> N;
 for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) cin >> MAP[i][j];

  dp[0][0] = 1;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      long long jump = MAP[i][j];
      if(i != N - 1 and i + jump < N){
        dp[i + jump][j] += dp[i][j];
      }
      if(j != N - 1 and j + jump < N){
        dp[i][j + jump] += dp[i][j];
      }
    }
  }
  cout << dp[N-1][N-1] << "\n";
  return 0;
}