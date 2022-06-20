#include <bits/stdc++.h>
using namespace std;
#define ll long long
int tc;
ll K, x;
ll ans;

void solution(){
  priority_queue<ll , vector<ll>, greater<ll>> pq; // 최소 힙
  cin >> K; ans = 0;
  while(K--){
    cin >> x;
    pq.push(x);
  }
  while(pq.size() != 1){
    ll min_1 = pq.top(); pq.pop();
    ll min_2 = pq.top(); pq.pop();
    pq.push(min_1 + min_2);
    ans += min_1 + min_2;
  }
  cout << ans << "\n";
}
int main(){
  ios::sync_with_stdio(false);
  cout.tie(0); cin.tie(0);

  cin >> tc;
  while(tc--){
    solution();
  }
  return 0;
}