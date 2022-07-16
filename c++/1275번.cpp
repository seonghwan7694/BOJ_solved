#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX = 1e5 + 1;
ll N, Q, x, y, a, b;
ll A[MAX], segment_tree[MAX * 4];

ll init_segment_tree(ll node_idx, ll start, ll end){
  if(start == end){
    return segment_tree[node_idx] = A[start];
  }
  return segment_tree[node_idx] = init_segment_tree(node_idx * 2, start, (start + end)/2) + init_segment_tree(node_idx * 2 + 1, (start + end)/2 + 1, end);
}

ll query_segment_tree(ll node_idx, ll start, ll end, ll left, ll right){
  if(left > end or right < start) return 0;

  if(left <= start and end <= right){
    return segment_tree[node_idx];
  }
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
  for(int i = 1; i <= N; i++){
    cin >> A[i];
  }

  init_segment_tree(1, 1, N);
  while(Q--){
    cin >> x >> y >> a >> b;
    if(x > y) swap(x, y);
    cout << query_segment_tree(1, 1, N, x, y) << "\n";
    update_segment_tree(1, 1, N, a, b - A[a]);
    A[a] = b;
  }

  return 0;
}