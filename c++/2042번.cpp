#include <bits/stdc++.h>
using namespace std;

long long N, M, K;
vector<long long> arr;
vector<long long> tree;
int mid;

long long init_tree(int node, int st, int en){
  if(st == en){
    return tree[node] = arr[st];
  }
  mid = (st + en)/2;
  return tree[node] = init_tree(node * 2, st, mid) + init_tree(node * 2 + 1, mid + 1, en);
}

void update_tree(int node, int st, int en, long long diff, int idx){ // update [left, right]
  if(!(st <= idx and idx <= en)) return;
  tree[node] += diff;
  mid = (st + en)/2;
  if(st != en){
    update_tree(node * 2, st, mid, diff, idx);
    update_tree(node * 2 + 1, mid + 1, en, diff, idx);
  }   
}

long long query(int node, int left, int right, int st, int en){ // get [left, right]
  if(left > en or right < st) return 0;
  if(left <= st and en <= right) return tree[node];
  mid = (st + en)/2;
  return query(node * 2, left, right, st, mid) + query(node * 2 + 1, left, right, mid + 1, en);
}

int main(){
  ios::sync_with_stdio(false);
  cin >> N >> M >> K;
  arr = vector<long long>(N + 1);
  long long h = (long long ) ceil(log2(N));
  long long tree_size = (1 << (h + 1));
  tree = vector<long long>(tree_size);


  for(int i = 1; i <= N; i++){
    cin >> arr[i];
  }

  init_tree(1, 1, N);

  for(long long i = 0, a, b, c, diff; i < M + K; i++) {
    cin >> a >> b >> c;
    if(a == 1){
      // change value
      diff = c - arr[b];
      arr[b] = c;
      update_tree(1, 1, N, diff, b);
    }else{
      cout << query(1, b, c, 1, N) << "\n";
    }
  }
}