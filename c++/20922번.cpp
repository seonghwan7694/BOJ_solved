#include <bits/stdc++.h>
using namespace std;

int N, K;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> K;
  vector<int> arr(N);
  int cnt[202020] = {0};
  for(int i = 0; i < N; i++) cin >> arr[i];

  int en = 0;
  int res = 0;
  cnt[arr[en]]++;
  for(int st = 0; st < N; st++){
    while(en < N - 1 and cnt[arr[en + 1]] < K){
      en++;
      cnt[arr[en]]++;
    }
    res = max(res, en - st + 1);
    cnt[arr[st]]--;
  }
  cout << res;
  return 0;
}