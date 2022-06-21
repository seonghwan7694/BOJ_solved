#include <bits/stdc++.h>
using namespace std;

int N; 
int dp[1001][3];
int cost[1001][3];
vector<int> ans;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;
  for(int i = 0; i < N; i++){
    for(int k = 0; k < 3; k++){
      cin >> cost[i][k];
    }
  }

  for(int i = 0; i < 3; i++){
    for(int k = 0; k < 3; k++){
      if(i == k) dp[0][k] = cost[0][k];
      else dp[0][k] = 987654321;
    }
    for(int j = 1; j < N; j++){
      dp[j][0] = min(dp[j-1][1], dp[j-1][2]) + cost[j][0];
      dp[j][1] = min(dp[j-1][0], dp[j-1][2]) + cost[j][1];
      dp[j][2] = min(dp[j-1][1], dp[j-1][0]) + cost[j][2];
    }
    for(int k = 0; k < 3; k++){
      if(i == k) continue;
      ans.push_back(dp[N-1][k]);
    }
  }
  cout << *min_element(ans.begin(), ans.end());
  return 0;
}