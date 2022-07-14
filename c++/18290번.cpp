#include <bits/stdc++.h>
using namespace std;
#define INF 210000000
int N, M, K, res = -INF;
int board[10][10];
bool chk[10][10];
bool selected[10][10];
int di[] = {-1, 1, 0, 0, 0};
int dj[] = {0, 0, -1, 1, 0};

bool check(int i, int j){
  for(int dir = 0; dir < 4; dir++){
    int ni = i + di[dir];
    int nj = j + dj[dir];
    if(ni < 0 or ni >= N or nj < 0 or nj >= M) continue;
    if(chk[ni][nj]) return false;
  }
  return true;
}

void dfs(int k, int tmp_res){
  if(k == K){
    res = max(tmp_res, res);
    return;
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      if(!chk[i][j] and check(i, j)){
        chk[i][j] = true;
        dfs(k + 1, tmp_res + board[i][j]);
        chk[i][j] = false;
      }
    }
  }
  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M >> K;
  for(int i = 0; i < N; i++){ for(int j = 0; j < M; j++){ cin >> board[i][j]; } }
  dfs(0, 0);
  cout << res << "\n";
  return 0;
}