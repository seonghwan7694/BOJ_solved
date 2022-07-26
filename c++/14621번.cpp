#include <bits/stdc++.h>
using namespace std;

int N, M, u, v, d;
int parent[1010];
vector<tuple<int, int, int>> edges;
char A[1010];

int Find(int x){
  if(parent[x] == x) return x;
  return parent[x] = Find(parent[x]);
}

bool Merge(int x, int y){
  if(A[x] == A[y]) return false;
  x = Find(x);
  y = Find(y);
  if(x == y) return false;
  if(x > y) parent[x] = y;
  else parent[y] = x;
  return true;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  for(int i = 1; i <= N; i++){
    parent[i] = i;
    cin >> A[i];
  }
  for(int i = 0; i < M; i++){
    cin >> u >> v >> d;
    edges.push_back({d, u, v});
  }
  int ans = 0, cnt = 0;
   sort(edges.begin(), edges.end());
   for(int i = 0; i < M; i++){
    auto cur = edges[i];
    if(Merge(get<1>(cur), get<2>(cur))){
      ans += get<0>(cur);
      cnt++;
    }
   }
   if(cnt != N - 1){
    cout << -1 << "\n";
   }else{
    cout << ans << "\n";
   }
    return 0;
}