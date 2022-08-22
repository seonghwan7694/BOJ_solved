#include <bits/stdc++.h>
using namespace std;

int N, L, ans;

void solution(vector<vector<int>>& board, vector<vector<bool>>& chk){
  for(int i = 0; i < N; i++){
    bool flag = false;
    for(int j = 1; j <= N; j++){
      if(j == N){
        ans++;
        break;
      }

      if(chk[i][j]) continue;

      if(board[i][j-1] - board[i][j] >= 1){ // 내려가는 길 : j <= x <= j + L - 1
        if(abs(board[i][j-1] - board[i][j]) > 1) break;
        if(j + L - 1 >= N) break;
        for(int jj = j; jj <= j + L - 1; jj++) if(board[i][j] != board[i][jj] or chk[i][jj]){
          flag = true;
          break;
        }
        if(flag) break;
        for(int jj = j; jj <= j + L - 1; jj++){ chk[i][jj] = true; }
      }else if(board[i][j-1] - board[i][j] <= -1){ // 올라가는 길 : j - L <= x <= j - 1
        if(abs(board[i][j-1] - board[i][j]) > 1) break; // j - 1 - j + L + 1 = L
        if(j - L < 0) break;
        for(int jj = j - 1; jj >= j - L; jj--) if(board[i][j-1] != board[i][jj] or chk[i][jj]){
          flag = true;
          break;
        }
        if(flag) break;
        for(int jj = j - 1; jj >= j - L; jj--){ chk[i][jj] = true; }
      }

    }

    fill(chk[i].begin(), chk[i].end(), false);
  }
  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> L;
  vector<vector<int>> board(N, vector<int>(N, 0));
  vector<vector<bool>> chk(N, vector<bool>(N, false));
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> board[i][j];
    }
  }

  solution(board, chk);
  for(int i = 0; i < N; i++){
    for(int j = 0; j < i; j++){
      swap(board[i][j], board[j][i]);
    }
  }
  solution(board, chk);
  cout << ans << "\n";
  return 0;
}