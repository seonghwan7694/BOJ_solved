#include <bits/stdc++.h>
using namespace std;

int N, M, tmp;
int parent[202];


int Find(int x){
  if(parent[x] == x) return x;
  else return parent[x] = Find(parent[x]);
}

void Union(int u, int v){
  u = Find(u);
  v = Find(v);
  if(u == v){
    return;
  }else{
    parent[u] = v;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  
  for(int i = 1; i <= 202; i++){
    parent[i] = i;
  }
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      cin >> tmp;
      if(tmp == 1) Union(i, j);
    }
  }

  int past, now;
  bool can_trip = true;
  cin >> past;
  for(int i = 1; i < M; i++){
    cin >> now;
    if(!can_trip) continue;
    if(Find(past) != Find(now)) can_trip = false;
    past = now;
  }
  if(can_trip) cout << "YES";
  else cout << "NO";
  return 0;
}