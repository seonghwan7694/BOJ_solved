#include <bits/stdc++.h>
using namespace std;

long long N, M, a, b, c;
const long long MAX = 1e6 + 1;
long long segment_tree[MAX * 3];
long long arr[MAX];
void update(long long node_idx, long long start, long long end, long long idx, long long val){
  if(idx < start or end < idx) return;
  segment_tree[node_idx] += val;
  if(start != end){
    update(node_idx * 2, start, (start + end)/2, idx, val);
    update(node_idx * 2 + 1, (start + end)/2 + 1, end, idx, val);
  }
}

long long sum(long long node_idx, long long start, long long end, long long left, long long right){
  if(left > end or right < start) return 0;
  if(left <= start and end <= right) return segment_tree[node_idx];
  return sum(node_idx * 2, start, (start + end)/2, left, right) + sum(node_idx * 2 + 1, (start + end)/2 + 1, end, left, right);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  
  while(M--){
    cin >> a >> b >> c;
    if(a == 0){
      if(b > c) swap(b, c);
      cout << sum(1, 1, N, b, c) << "\n";
    }else{
      update(1, 1, N, b, c - arr[b]);
      arr[b] = c;
    }
  }

  return 0;
}