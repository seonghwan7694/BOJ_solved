#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 1;
const int MOD = 1e9 + 7;

int N, M, K;
long long arr[MAX * 4];
long long segment_tree[MAX * 4];

long long initialize_segment_tree(int node_idx, int start, int end){
  // 리프노드일 경우
  if(start == end){
    return segment_tree[node_idx] = arr[start];
  }

  // 리프노드가 아닐 경우
  int mid = (start + end)/2;
  return segment_tree[node_idx] = (initialize_segment_tree(node_idx * 2, start, mid) * initialize_segment_tree(node_idx * 2 + 1, mid + 1, end))%MOD;
}

long long query(int node_idx, int start, int end, int left, int right){
  if(left > end or right < start) return 1;
  if(left <= start and end <= right) return segment_tree[node_idx];

  int mid = (start + end)/2;
  return (query(node_idx * 2, start, mid, left, right) * query(node_idx * 2 + 1, mid + 1, end, left, right))%MOD;
}

void update_segment_tree(int node_idx, int start, int end, int idx, long long val){
  if(idx < start or end < idx) return;

  if(start == end){
    segment_tree[node_idx] = val;
    return;
  }
  int mid = (start + end)/2;
  update_segment_tree(node_idx * 2, start, mid, idx, val);
  update_segment_tree(node_idx * 2 + 1, mid + 1, end, idx, val);
  segment_tree[node_idx] = (segment_tree[node_idx * 2] * segment_tree[node_idx * 2 + 1])%MOD;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M >> K;
  for(int i = 1; i <= N; i++){
    cin >> arr[i];
  }

  initialize_segment_tree(1, 1, N);

  for(int i = 1; i <= M + K; i++){
    long long a, b, c;
    cin >> a >> b >> c;
    if(a == 1){
      update_segment_tree(1, 1, N, b, c);
    }else if(a == 2){
      cout << query(1, 1, N, b, c) << "\n";
    }
  }
  return 0;
}