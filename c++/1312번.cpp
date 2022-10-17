#include <bits/stdc++.h>
using namespace std;

unsigned long long A, B, N, res;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> A >> B >> N;
  if(A % B == 0){
    cout << 0 << "\n";
    return 0;
  }
  if(A > B) A = A % B;
  while(N--){
    A *= 10;
    res = (A/B);
    A %= B;
  }
  cout << res << "\n";
  return 0;
}