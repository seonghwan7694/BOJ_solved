#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
int ans[10];

void func(int k, int prev){
  if(k == M){
    for(int i = 0; i < M; i++){
      cout << ans[i] << " ";
    }
    cout << "\n";
    return;
  }


  for(int i = 0; i < N; i++){
    if(prev <= arr[i]){
      ans[k] = arr[i];
      func(k + 1, ans[k]);
      ans[k] = 0;
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
  func(0, -1);
  return 0;
}