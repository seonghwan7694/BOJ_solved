#include <bits/stdc++.h>
using namespace std;

int P, L, V, tc;

void solution(){
  int ans = 0;
  ans += V/L * P;
  ans += V%L > P ? P : V%L;
  cout << "Case " << ++tc << ": " << ans << "\n";
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  while(true){
    cin >> P >> L >> V;
    if(!P and !L and !V) break;
    solution();
  }
  return 0;
}