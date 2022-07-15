#include <bits/stdc++.h>
using namespace std;

int N, L, R, X, ans;
int A[15];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> N >> L >> R >> X;
  for(int i = 0; i < N; i++){ cin >> A[i]; }
  for(int i = 1; i < (1 << N); i++){
    int ml = 2e9, mr = 0, sum = 0, cnt = 0;
    for(int j = 0; j < N; j++){
      if(i & (1 << j)){
        mr = max(mr, A[j]);
        ml = min(ml, A[j]);
        sum += A[j];
        cnt++;
      }
    }
    if(cnt >= 2 and L <= sum and sum <= R and mr - ml >= X) ans++;
  }

  cout << ans << "\n";
  return 0;
}