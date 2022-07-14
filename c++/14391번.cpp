#include <bits/stdc++.h>
using namespace std;

int N, M;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  vector<vector<int>> P(N, vector<int>(M));
  for(int i = 0; i < N; i++){
    string tmp;
    cin >> tmp;
    for(int j = 0; j < M; j++){
      P[i][j] = tmp[j] - '0';
    }
  }
  /*
  0 : 가로 방향
  1 : 세로 방향
  */
  int max_sum = 0;
  for(int bitset = 0; bitset < (1 << N * M); bitset++){ // 모두 가로방향일때부터 모두 세로방향일때까지
    int sum = 0;

    // 가로 숫자 합 구하기
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
        if(~bitset & (1 << (i * M + j))){ // i행 j열이 가로방향인지 확인
          int num = 0;
          while(j < M and ~bitset & (1 << (i * M + j))){
            num *= 10;
            num += P[i][j];
            j++;
          }
          sum += num;
        }
      }
    }

    // 세로 숫자 합 구하기
    for(int j = 0; j < M; j++){
      for(int i = 0; i < N; i++){
        if(bitset & (1 << (i * M + j))){ // i행 j열이 켜져있는지 확인
          int num = 0;
          while(i < N and bitset & (1 << (i * M + j))){
            num *= 10;
            num += P[i][j];
            i++;
          }
          sum += num;
        }
      }
    }

    max_sum = max(max_sum, sum);
  }
  cout << max_sum << "\n";
  return 0;
}