#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int N, M, result;
int board[51][51];
vector<pair<int, int>> chicken, house;
bool visited[13];

int distance(pair<int, int> a, pair<int, int> b){
  return abs(a.first - b.first) + abs(a.second - b.second);
}

void DFS(int idx, int selected){
  if(selected == M){
    int tmp_result = 0;
    for(int i = 0; i < house.size(); i++){
      int dist = INF;
      for(int j  = 0; j < chicken.size(); j++){
        if(visited[j]) dist = min(dist, distance(house[i], chicken[j]));
      }
      tmp_result += dist;
    }
    result = min(result, tmp_result);
    return;
  }

  if(idx == chicken.size()) return;

  visited[idx] = true;
  DFS(idx + 1, selected + 1);
  visited[idx] = false;
  DFS(idx + 1, selected);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> board[i][j];
      if(board[i][j] == 1){
        house.push_back({i, j});
      }else if(board[i][j] == 2){
        chicken.push_back({i, j});
      }
    }
  }
  result = INF;
  DFS(0, 0);
  cout << result << "\n";
  return 0;
}