#include <bits/stdc++.h>
using namespace std;

int N, M;
bool is_used[10];
int arr[10];

void func(int n, int k){ // 현재 탐색하는 숫자는 n이며 , 현재까지 k개를 골랐습니다.
  if(k == M){ // M개를 골랐으면, 출력합니다.
    for(int i = 0; i < M; i++){
      cout << arr[i] << " ";
    }
    cout << "\n";
    return;
  }

  for(int i = n; i <= N; i++){
    if(!is_used[i]){
      is_used[i] = true; arr[k] = i;
      func(i, k + 1);
      is_used[i] = false; arr[k] = 0;
    }
  }

  
  return;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  func(1, 0); // 현재 탐색하려는 숫자는 1이며, 현재까지 0개를 골랐습니다.

  return 0;
}