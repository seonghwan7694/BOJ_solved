#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
int ans[10];
bool is_used[10];

void func(int k){ // 현재 k개의 수를 정했다.
  if(k == M){
    for(int i = 0; i < M; i++){
      cout << ans[i] << " ";
    }
    cout << "\n";
    return;
  }
  for(int i = 0; i < N; i++){
    if(!is_used[i]){
      ans[k] = arr[i]; is_used[i] = true;
      func(k + 1);
      ans[k] = 0; is_used[i] = false;
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  for(int i = 0; i < N; i++){
    cin >> arr[i];
  }
  sort(arr, arr + N);
  func(0);
  return 0;
}