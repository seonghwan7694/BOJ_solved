#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll N;
ll p;
pair<ll, ll> food[10];
ll ans = 2929929292929;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;
  for(ll i = 0; i < N; i++){
    cin >> food[i].first >> food[i].second;
  }

  for(ll bitset = 1; bitset < (1 << N); bitset++){
    ll a = 1, b = 0;
    for(int i = 0; i < N; i++){
      if(bitset & (1 << i)){
        a *= food[i].first;
        b += food[i].second;
      }
    }
    ans = min(ans, abs(a - b));
  }
  cout << ans << "\n";
  return 0;
}