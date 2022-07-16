#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 1;

int N, K, a, b;
char op;

int init_segment_tree(int segment_tree[], int node_idx, int start, int end, int A[]){
  if(start == end){
    if(A[start] > 0){
      return segment_tree[node_idx] = 1;
    }else if(A[start] == 0){
      return segment_tree[node_idx] = 0;
    }
    return segment_tree[node_idx] = -1;
  }
  return segment_tree[node_idx] = init_segment_tree(segment_tree, node_idx * 2, start, (start + end)/2, A) * init_segment_tree(segment_tree, node_idx * 2 + 1, (start + end)/2 + 1, end, A);
}

int update_segment_tree(int segment_tree[], int node_idx, int start, int end, int idx, int val){

  if(idx < start or end < idx){
    return segment_tree[node_idx];
  }
  if(start == end){
    return segment_tree[node_idx] = val;
  }

  return segment_tree[node_idx] = update_segment_tree(segment_tree, node_idx * 2, start, (start + end)/2, idx, val) * update_segment_tree(segment_tree, node_idx * 2 + 1, (start + end)/2 + 1, end, idx, val);
}

int query_segment_tree(int segment_tree[], int node_idx, int start, int end, int left, int right){
  if(left > end or right < start) return 1;
  if(left <= start and end <= right){
    return segment_tree[node_idx];
  }
  return query_segment_tree(segment_tree, node_idx * 2, start, (start + end)/2, left, right) * query_segment_tree(segment_tree, node_idx * 2 + 1, (start + end)/2 + 1, end, left, right);
}

void solution(){
  int A[MAX] = {0};
  int segment_tree[MAX * 4] = {0};

  for(int i = 1; i <= N; i++){
    cin >> A[i];
  }

  init_segment_tree(segment_tree, 1, 1, N, A);

  while(K--){
    cin >> op >> a >> b;
    if(op == 'C'){
      // A[a] = b로 변경
      A[a] = b;
      if(b > 0) update_segment_tree(segment_tree, 1, 1, N, a, 1);
      if(b == 0) update_segment_tree(segment_tree, 1, 1, N, a, 0);
      if(b < 0) update_segment_tree(segment_tree, 1, 1, N, a, -1);
    }else{
      // A[a] ~ A[b] 곱샘
      int ret = query_segment_tree(segment_tree, 1, 1, N, a, b);
      if(ret > 0) cout << '+';
      if(ret == 0) cout << '0';
      if(ret < 0) cout << '-';
    }
  }

}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  while(cin >> N){
    cin >> K;
    solution();
    cout << "\n";
  }

  return 0;
}