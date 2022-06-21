// 명제 : 가장 가격이 높은 보석부터 확인하며 해당 보석을 담을 수 있는 가방 중 최대 무게가 가장 작은 가방을 이용해 보석을 담는게 이득이다.

// 1. 보석의 가치순으로 내림차순 정렬, 가방의 무게는 멀티셋에 저장
// 2. i번째로 큰 가치를 가지는 보석에 대해, 그 보석을 담을 수 있는 가방 중 가장 작은걸 선행(lower_bound)
// 2-1. ans변수에 i번째 보석의 가치를 더해주고, 그 보석을 담은 가방을 멀티셋에서 삭제
// 3. i가 K(or K - 1)가 될때까지 수행

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// 10^5 * 10^6 -> int형 오버플로우 주의 -> 해결

int N, K;
multiset<ll> bag; // weight
vector<pair<ll, ll>> jewel; // value, weight
ll ans = 0;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);



  cin >> N >> K;
  for(int i = 0; i < N; i++){
    ll weight, value; cin >> weight >> value;
    jewel.push_back({value, weight});
  }
  for(int i = 0; i < K; i++){
    ll weight; cin >> weight;
    bag.insert(weight);
  }
  sort(jewel.begin(), jewel.end(), [](pair<ll, ll> &a, pair<ll, ll> &b){ return a.first > b.first; });

  // for(auto x : jewel) cout << x.first << " ";

  for(int i = 0; i < N and !bag.empty(); i++){ // K <= N일때만 유효? -> 걍 맞네.. 허무 ㅋ
    auto iter = bag.begin();
    if((iter = bag.lower_bound(jewel[i].second)) != bag.end()){
      bag.erase(iter);
      ans += jewel[i].first;
    }
  }

  cout << ans << "\n";
  return 0;
}