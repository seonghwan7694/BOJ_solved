#include <bits/stdc++.h>
using namespace std;

int N, M;
bool is_used[10];
int arr[10];


void func(int k){ // 현재 k개의 수를 택했음
  if(k == M){
    for(int i = 0; i < M; i++){
      cout << arr[i] << " ";
    }
    cout << "\n";
    return;
  }

  for(int i = 1; i <= N; i++){
    if(!is_used[i]){
      is_used[i] = true; arr[k] = i;
      func(k + 1);
      is_used[i] = false; arr[k] = 0;
    }
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;

  func(0);

  return 0;
}