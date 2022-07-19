#include <bits/stdc++.h>
using namespace std;
#define INF 9876543210
#define ll long long
typedef struct{
  ll u, v, c;
}Node;

ll V, E, A, B, C;
vector<Node> Edges;
Node u;
ll Dist[505];

void Bellan_Ford(){
  Dist[1] = 0;
  for(int i = 1; i <= V - 1; i++){
    for(int j = 0; j < Edges.size(); j++){
      ll From = Edges[j].u;
      ll To = Edges[j].v;
      ll Cost  = Edges[j].c;

      if(Dist[From] == INF) continue;
      if(Dist[To] > Dist[From] + Cost) Dist[To] = Dist[From] + Cost;
    }
  }

  for(int i = 0; i < Edges.size(); i++){
    ll From = Edges[i].u;
    ll To = Edges[i].v;
    ll Cost = Edges[i].c;

    if(Dist[From] == INF) continue;
    if(Dist[To] > Dist[From] + Cost){
      cout << -1 << "\n";
      return;
    } 
  }

  for(int i = 2; i <= V; i++){
    if(Dist[i] == INF){
      cout << -1 << "\n";
    }else{
      cout << Dist[i] << "\n";
    }
  }
  return;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> V >> E;
  fill(Dist, Dist + 505, INF);
  while(E--){
    cin >> A >> B >> C;
    u.u = A, u.v = B, u.c = C;
    Edges.push_back(u);
  }

  Bellan_Ford();

  return 0;
}