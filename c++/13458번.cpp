#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll N, A[1010101], B, C, ans, dp[1010101], cnt = 2;

/*
3
3 4 5
2 2

dp[1] = 1
dp[2] = 1;
dp[3] = 2;
dp[4] = 2;
dp[5] = 3;

*/
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;
  for(int i = 1; i <= N; i++){
    cin >> A[i];
  }
  cin >> B >> C;

  for(int i = 1; i <= B; i++){
    dp[i] = 1;
  }
  for(int i = B + 1; i <= 1000001;){
    for(int j = i; j < i + C and j <= 1000001; j++){
      dp[j] = cnt;
    }
    i = i + C;
    cnt++;
  }
  for(int i = 1; i <= N; i++){
    ans += dp[A[i]];
  }
  cout << ans << "\n";
  return 0;
}