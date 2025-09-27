#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define x first
#define y second
ll N;
pair<ll, ll> A[101010], B[101010];

inline ll Square(ll v){return v * v;}
inline ll Dist(const pair<ll, ll> &p1, const pair<ll, ll> &p2){
  return Square(p1.x - p2.x) + Square(p1.y - p2.y);
}

struct CompareY{
  bool operator()(const pair<ll,ll> &p1, const pair<ll,ll> &p2) const{
    return tie(p1.y, p1.x) < tie(p2.y, p2.x);
  }
};

ll func(int l, int r){
  if(l == r) return LLONG_MAX;
  int m = (l + r) / 2;
  ll xm = A[m].x, d = min(func(l, m), func(m + 1, r));
  merge(A + l, A + m + 1, A + m + 1, A + r + 1, B + l, CompareY());
  copy(B + l, B + r + 1, A + l);

  vector<pair<ll,ll>> P;
  for(int i = l; i <= r; i++) if(Square(A[i].x - xm) < d) P.push_back(A[i]);
  for(int i = 0; i < P.size(); i++){
    for(int j = i - 1; j >= 0; j--){
      if(Square(P[i].y - P[j].y) < d) d = min(d, Dist(P[i], P[j]));
      else break;
    }
  }
  return d;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for(int i = 1, a, b; i <= N; i++){
    cin >> a >> b;
    A[i] = {a, b};
  }
  sort(A + 1, A + N + 1);
  cout << func(1, N) << "\n";
  return 0;
}