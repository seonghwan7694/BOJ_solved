#include <bits/stdc++.h>
using namespace std;

int N, M, op, a, b;
int A[101010];
pair<int, int> segment_tree[101010 * 4];

pair<int, int> init_segment_tree(int node_idx, int start, int end){
  if(start == end){
    return segment_tree[node_idx] = {A[start], start};
  }
  pair<int, int> L = init_segment_tree(node_idx * 2, start, (start + end)/2);
  pair<int, int> R = init_segment_tree(node_idx * 2 + 1, (start + end)/2 + 1, end);
  if(L.first > R.first) segment_tree[node_idx] = L;
  else segment_tree[node_idx] = R;
  return segment_tree[node_idx];
}

pair<int, int> update_segment_tree(int node_idx, int start, int end, int idx, int val){
  if(idx < start or end < idx) return segment_tree[node_idx];
  if(start == end) return segment_tree[node_idx] = {val, idx};
  pair<int, int> L = update_segment_tree(node_idx * 2, start, (start + end)/2, idx, val);
  pair<int, int> R = update_segment_tree(node_idx * 2 + 1, (start +end)/2 + 1, end, idx, val);
  if(L.first > R.first){
    segment_tree[node_idx] = L;
  }else{
    segment_tree[node_idx] = R;
  }
  return segment_tree[node_idx];
}

pair<int, int> query_segment_tree(int node_idx, int start, int end, int left, int right){
  if(left > end or right < start){
    return {-1, -1};
  }

  if(left <= start and end <= right){
    return segment_tree[node_idx];
  }
  pair<int, int> L = query_segment_tree(node_idx * 2, start, (start + end)/2, left, right);
  pair<int ,int> R = query_segment_tree(node_idx * 2 + 1, (start + end)/2 + 1, end, left, right);
  if(L.first > R.first) return L;
  return R;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;
  for(int i = 1; i <= N; i++){
    cin >> A[i];
  }
  init_segment_tree(1, 1, N);
  cin >> M;
  while(M--){
    cin >> op >> a >> b;
    if(op == 1){
      // 업데이트 세그먼트 트리
      update_segment_tree(1, 1, N, a, b);
    }else{
      // 쿼리 세그먼트 트리
      pair<int, int> T = query_segment_tree(1, 1, N, a, b);
      pair<int, int> L = query_segment_tree(1, 1, N, a, T.second - 1);
      pair<int, int> R = query_segment_tree(1, 1, N, T.second + 1, b);
      cout << T.first + max(L.first, R.first) << "\n";
    }
  }
  return 0;  
}