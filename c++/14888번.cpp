#include <bits/stdc++.h>
using namespace std;
#define INF 2100000000

int N;
int arr[11];
int oper[4];
int max_res = -INF, min_res = INF;

// func(k, prev_res) : 현재까지 k개의 연산을 사용했고, 이전 결과는 prev_res입니다.
void func(int k, int prev_res){ 
  if(k == N - 1){
    max_res = max(prev_res, max_res);
    min_res = min(prev_res, min_res);
    return;
  }

  for(int i = 0; i < 4; i++){
    if(oper[i] > 0){
      oper[i]--;
      if(i == 0) func(k + 1, prev_res + arr[k + 1]);
      if(i == 1) func(k + 1, prev_res - arr[k + 1]);
      if(i == 2) func(k + 1, prev_res * arr[k + 1]);
      if(i == 3) func(k + 1, prev_res / arr[k + 1]);
      oper[i]++;
    }
  }
}
int main(){
  ios::sync_with_stdio(false);
  cout.tie(0); cout.tie(0);

  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> arr[i];
  }
  for(int i = 0; i < 4; i++){
    cin >> oper[i];
  }
  func(0, arr[0]);
  cout << max_res << "\n" << min_res << "\n";
  return 0;
}