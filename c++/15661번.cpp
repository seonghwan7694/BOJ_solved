#include <bits/stdc++.h>
using namespace std;

int res = 987654321;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N;
  cin >> N;
  vector<vector<int>> S(N, vector<int>(N));
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> S[i][j];
    }
  }

  // 모든 사람이 링크 팀 ~ 모든 사람이 스타트 팀
  for(int bitset = 0; bitset < (1 << N); bitset++){ 
    int start_res = 0, link_res = 0; // 1 : 스타트, 0 : 링크
    for(int i = 0; i < N - 1; i++){
      for(int j = i + 1; j < N; j++){
        if((bitset & (1 << i)) && (bitset & (1 << j))){
          start_res += S[i][j] + S[j][i];
        }
        if((~bitset & (1 << i)) && (~bitset & (1 << j))){
          link_res += S[i][j] + S[j][i];
        }
      }
    }
    res = min(res, abs(start_res - link_res));
  }
  cout << res << "\n";
  return 0;
}