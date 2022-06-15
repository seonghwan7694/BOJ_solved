#include <bits/stdc++.h>
using namespace std;

int N, M, arr[101][101], ans;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  ans = N*M;
  for(int i = 1; i <= N; i++){
    int sum = 0;
    for(int j = 1; j <= M; j++){
      cin >> arr[i][j];
      if(arr[i][j] > arr[i][j-1]) sum += arr[i][j] - arr[i][j-1];
    }
    ans += sum;
  }
  for(int j = 1; j <= M; j++){
    int sum = 0;
    for(int i = 1; i <= N; i++){
      if(arr[i][j] > arr[i-1][j]) sum += arr[i][j] - arr[i-1][j];
    }
    ans += sum;
  }

  cout << ans*2 << "\n";
  return 0;
}