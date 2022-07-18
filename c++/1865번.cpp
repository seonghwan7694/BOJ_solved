#include <bits/stdc++.h>
using namespace std;

int TC;
int N, M, W;
int Dist[505];
const int INF = 987654321;
vector<pair<pair<int, int>, int>> Edge;

bool Bellan_Ford(){
  fill(Dist, Dist + 505, INF);
  Dist[1] = 0;
  for(int i = 1; i <= N - 1; i++){
    for(int j = 0; j < Edge.size(); j++){
      int From = Edge[j].first.first;
      int To = Edge[j].first.second;
      int Cost = Edge[j].second;

      if(Dist[From] == INF) continue;
      if(Dist[To] > Dist[From] + Cost) Dist[To] = Dist[From] + Cost;
    }
  }

  for(int i = 0; i < Edge.size(); i++){
      int From = Edge[i].first.first;
      int To = Edge[i].first.second;
      int Cost = Edge[i].second;
    
      if(Dist[To] > Dist[From] + Cost){
        return true;
      }
  }
  return false;
}
void solution(){
  cin >> N >> M >> W;
  Edge.clear();
  for(int i = 0; i < M; i++){
    int S, E, T;
    cin >> S >> E >> T;
    Edge.push_back({{S, E}, T});
    Edge.push_back({{E, S}, T});
  }
  for(int i = 0; i < W; i++){
    int S, E, T;
    cin >> S >> E >> T;
    Edge.push_back({{S, E}, -T});
  }
  cout << (Bellan_Ford() ? "YES" : "NO") << "\n";
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> TC;
  while(TC--){
    solution();
  }
  return 0;
}