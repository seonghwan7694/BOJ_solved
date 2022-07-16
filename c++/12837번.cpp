#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX = 1e6 + 1;

ll N, Q, A[MAX], a, b, c, segment_tree[MAX * 4];

ll query_segment_tree(ll node_idx, ll start, ll end, ll left, ll right){
  if(left > end or right < start) return 0;
  if(left <= start and end <= right) return segment_tree[node_idx];
  return query_segment_tree(node_idx * 2, start, (start + end)/2, left, right) + query_segment_tree(node_idx * 2 + 1, (start + end)/2 + 1, end, left, right);
}

void update_segment_tree(ll node_idx, ll start, ll end, ll idx, ll diff){
  if(idx < start or end < idx) return;
  segment_tree[node_idx] += diff;
  if(start != end){
    update_segment_tree(node_idx * 2, start, (start + end)/2, idx, diff);
    update_segment_tree(node_idx * 2 + 1, (start + end)/2 + 1, end, idx, diff);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> Q;
  while(Q--){
    cin >> a >> b >> c;
    if(a == 1){
      update_segment_tree(1, 1, N, b, c);
      A[b] = c;
    }else{
      cout << query_segment_tree(1, 1, N, b, c) << "\n";
    }
  }

  return 0;
}