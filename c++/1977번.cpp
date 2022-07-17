#include <bits/stdc++.h>
using namespace std;

int N, M, ans, min_value = 1010101;
bool dp[10101];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  for(int i = 1; i <= 100; i++){
    dp[i * i] = true;
  }
  for(int i = N; i <= M; i++){
    if(dp[i]){
      min_value = min(min_value, i);
      ans += i;
    }
  }
  if(!ans){
    cout << -1 << "\n";
    return 0;
  }
  cout << ans << "\n";
  cout << min_value << "\n";
  return 0;
}