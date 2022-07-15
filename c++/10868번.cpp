#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 1;
const int INF = 1e9 + 1;

long long arr[MAX];
long long segmentTree[4 * MAX];

long long initializeSegmentTree(int left, int right, int node){
  if(left == right){
    return segmentTree[node] = arr[left];
  }
  int mid = (left + right)/2;
  return segmentTree[node] = min(initializeSegmentTree(left, mid, node * 2), initializeSegmentTree(mid + 1, right, node * 2 + 1));
}

long long query(int left, int right, int node, int nodeLeft, int nodeRight){
  if(nodeLeft > right or nodeRight < left){
    return INF;
  }
  if(nodeLeft >= left and right >= nodeRight){
    return segmentTree[node];
  }
  int mid = (nodeLeft + nodeRight)/2;
  return min(query(left, right, node * 2, nodeLeft, mid), query(left, right, node * 2 + 1, mid + 1, nodeRight));
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N, M;
  cin >> N >> M;

  for(int i = 1; i <= N; i++){
    cin >> arr[i];
  }

  initializeSegmentTree(1, N, 1);
  
  for(int i = 1; i <= M; i++){
    int a, b;
    cin >> a >> b;
    cout << query(a, b, 1, 1, N) << "\n";
  }


  return 0;
}