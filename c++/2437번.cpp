#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll N;
vector<ll> A;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  A = vector<ll>(N);
  for(ll i = 0; i < N; i++){
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  int res = 1;
  for(int i = 0; i < N ; i++){
    if(A[i] > res) break;
    res += A[i];
  }
  cout << res << "\n";
  return 0;
}