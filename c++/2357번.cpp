#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 1;
const int INF = 1e9 + 1;
int N, M;
int arr[MAX];
pair<int, int> segment_tree[MAX * 3];

pair<int, int> init_segment_tree(int node_idx, int start, int end){
  if(start == end){
    return {segment_tree[node_idx].first = arr[start], segment_tree[node_idx].second = arr[start]};
  }
    auto x = init_segment_tree(node_idx * 2, start, (start + end)/2);
    auto y = init_segment_tree(node_idx * 2 + 1, (start + end)/2 + 1, end);
    return segment_tree[node_idx] = {min(x.first, y.first), max(x.second, y.second)};
}

pair<int, int> query(int node_idx, int start, int end, int left, int right){
  if(left > end or right < start){
    return {INF, -INF};
  }

  if(left <= start and end <= right){
    return {segment_tree[node_idx].first, segment_tree[node_idx].second};
  }
  auto x = query(node_idx * 2, start, (start + end)/2, left, right);
  auto y = query(node_idx * 2 + 1, (start + end)/2 + 1, end, left, right);
  return {min(x.first, y.first), max(x.second, y.second)};
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  for(int i = 1; i <= N; i++){
    cin >> arr[i];
  }
  init_segment_tree(1, 1, N);
  for(int i = 1; i <= M; i++){
    int a, b;
    cin >> a >> b;
    auto ret = query(1, 1, N, a, b);
    cout << ret.first << " " << ret.second << "\n";
  }
  return 0;
}