#include <bits/stdc++.h>
using namespace std;

int arr[1010101];
int N, K, cnt;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> K;
  for(int i = 0; i < N; i++) cin >> arr[i];

  int cnt = 0; if(arr[0]%2 == 1) cnt++;

  int en = 0, ans = 0;
  for(int st = 0; st < N; st++){
    while(en < N - 1 and cnt + arr[en+1]%2 <= K){
      en++;
      cnt += arr[en]%2;
    }
    ans = max(ans, en - st + 1 - cnt);
    cnt -= arr[st]%2;
  }
  cout << ans;
  return 0;
}