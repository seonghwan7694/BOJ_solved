#include <bits/stdc++.h>
using namespace std;

int N, T, s, x, y, M, A, B;
const int INF = 987654321;
int board[1010][1010]; // board[A][B] = cost : A 도시에서 B 도시로 가는 cost 최단 시간
vector<tuple<int, int, int, int>> edges; // {node_idx, x, y, s}

void floyd(){
  for(int k = 1; k <= N; k++){
    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= N; j++){
        if(i == j) continue;
        if(board[i][j] > board[i][k] + board[k][j]) board[i][j] = board[i][k] + board[k][j];
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> T;
  
  for(int i = 0; i < 1010; i++){
    fill(board[i], board[i] + 1010, INF);
  }
  for(int i = 1; i <= N; i++){
    cin >> s >> x >> y;
    edges.push_back({i, x, y, s});
  }

  for(int i = 0; i < edges.size(); i++){
    for(int j = 0; j < i; j++){
      auto A = edges[i];
      auto B = edges[j];
      int dist = abs(get<1>(A) - get<1>(B)) + abs(get<2>(A) - get<2>(B));
      if(get<3>(A) == 1 and get<3>(B) == 1){
        board[get<0>(A)][get<0>(B)] = min(T, dist);
        board[get<0>(B)][get<0>(A)] = min(T, dist);
      }else{
        board[get<0>(A)][get<0>(B)] = dist;
        board[get<0>(B)][get<0>(A)] = dist;
      }
    }
  }
  floyd();
  cin >> M;
  while(M--){
    cin >> A >> B;
    cout << board[A][B] << "\n";
  }


  return 0;
}