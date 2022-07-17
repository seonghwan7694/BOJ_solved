#include <bits/stdc++.h>
using namespace std;

int N, M;
/*

1, 1 -> 0
1, 2 -> 1
1, 3 -> 2
1, 4 -> 3
1, n -> n - 1

2, 1 -> 1
2, 2 -> 3
2, 3 -> 5

3, 1 -> 2
3, 2 -> 5

*/
int dp[303][303];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  for(int i = 1; i < 303; i++){
    dp[i][1] = i - 1;
    for(int j = 2; j < 303; j++){
      dp[i][j] = dp[i][j - 1] + i;
    }
  }
  cout << dp[N][M] << "\n";
  return 0;
}