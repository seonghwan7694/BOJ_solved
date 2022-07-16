#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
const int sz = 1 << 17;
vector<int> tree[sz*2];
int N, a[sz], Q, b, c, d;
void add(int x, int v){
  x += sz; tree[x].push_back(v);
}

void build(){
  for(int i = 1; i <= N; i++) add(i, a[i]);
  for(int i = sz - 1; i; i--){
    tree[i].resize(tree[i*2].size() + tree[i*2 + 1].size());
    merge(all(tree[i*2]), all(tree[i*2+1]), tree[i].begin());
  }
}

int query(int l, int r, int k){
  l |= sz, r |= sz;
  int ret = 0;
  while(l <= r){
    if(l & 1) ret += tree[l].end() - upper_bound(all(tree[l]), k), l++;
    if(~r & 1) ret += tree[r].end() - upper_bound(all(tree[r]), k), r--;
    l >>= 1, r >>= 1;
  }
  return ret;
}

int main(){
  ios::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++){
      cin >> a[i];
    }
    cin >> Q;
    build();
    while(Q--){
      cin >> b >> c >> d;
      cout << query(b, c, d) << "\n";
    }
   return 0;
}