#include <bits/stdc++.h>
using namespace std;

/*
N개의 운동 키트에 대한 정보가 주어졌을 때
N일간 하루에 1개씩의 운동 키트를 사용하는 모든 경우 중에서
운동 기간동안 항상 중량이 500 이상이 되도록 하는 경우의 수를 출력하시오.
*/

int N, K, a[10], ret;
bool visited[10];

void func(int n, int k){ // 현재 n일차이고, 현재 중량은 k이다.
  if(k < 500) return;
  if(n == N){
    ret += 1;
    return;
  }

  for(int i = 1; i <= N; i++){
    if(!visited[i]){
      visited[i] = true;
      func(n + 1, k - K + a[i]);
      visited[i] = false;
    }
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> K;
  for(int i = 1; i <= N; i++){
    cin >> a[i];
  }

  func(0, 500);
  cout << ret << "\n";
  return 0;
}