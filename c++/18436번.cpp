#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MAX = 1e5 + 1;
const long long INF = 1e9 + 1;

long long N, M, a, b, c;
ll A[MAX];
pair<ll, ll> segment_tree[MAX * 4]; // {홀수, 짝수}

pair<ll, ll> init_segment_tree(ll node_idx, ll start, ll end){
  if(start == end){
    if(A[start] % 2 == 0) return segment_tree[node_idx] = {0, 1};
    else return segment_tree[node_idx] = {1, 0};
  }
  ll mid = (start + end)/2;
  auto left_node = init_segment_tree(node_idx * 2, start, mid);
  auto right_node = init_segment_tree(node_idx * 2 + 1, mid + 1, end);
  return segment_tree[node_idx] = {left_node.first + right_node.first, left_node.second + right_node.second};
}

void update_segment_tree(ll node_idx, ll start, ll end, ll idx, pair<ll, ll> val){
  if(idx < start or end < idx) return;

  segment_tree[node_idx].first += val.first;
  segment_tree[node_idx].second += val.second;

  if(start != end){
    ll mid = (start + end)/2;
    update_segment_tree(node_idx * 2, start, mid, idx, val);
    update_segment_tree(node_idx * 2 + 1, mid + 1, end, idx, val);
  }
}

pair<ll, ll> query_segment_tree(ll node_idx, ll start, ll end, ll left, ll right){
  if(left > end or right < start) return {0, 0};

  if(left <= start and end <= right){
    return segment_tree[node_idx];
  }
  ll mid = (start + end)/2;
  auto left_node = query_segment_tree(node_idx * 2, start, mid, left, right);
  auto right_node = query_segment_tree(node_idx * 2 + 1, mid + 1, end, left, right);
  return {left_node.first + right_node.first, left_node.second + right_node.second};
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;
  for(int i = 1; i <= N; i++) cin >> A[i];
  init_segment_tree(1, 1, N);

  cin >> M;
  while(M--){
    cin >> a >> b >> c;
    if(a == 1){
      if(A[b] % 2 == 0){ // 원래 있던게 짝수
        if(c % 2 == 0) continue; // 그대로 놔둬도 무방
        if(c % 2 == 1) update_segment_tree(1, 1, N, b, {1, -1}); // 새로운게 홀수이면
      }else{ // 원래 있던게 홀수
        if(c % 2 == 0) update_segment_tree(1, 1, N, b, {-1, 1}); // 새로운게 짝수이면
        if(c % 2 == 1) continue; // 그대로 놔둬도 무방
      }
      A[b] = c;
    }else if(a == 2){
      cout << query_segment_tree(1, 1, N, b, c).second << "\n";
    }else if(a == 3){
      cout << query_segment_tree(1, 1, N, b, c).first << "\n";
    }
  }

  
  return 0;
}