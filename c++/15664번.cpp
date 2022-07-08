#include <bits/stdc++.h>
using namespace std;

int N, M;
bool is_used[10];
int arr[10], res[10];

void func(int k, int prev){
  if(k == M){
    for(int i = 0; i < M; i++){
      cout << res[i] << " ";
    }
    cout << "\n";
    return;
  }
  int xx = 0;
  for(int i = 0; i < N; i++){
    if(!is_used[i] and xx != arr[i] and prev <= arr[i]){
      is_used[i] = true;
      res[k] = arr[i];

      xx = res[k];
      func(k+1, arr[i]);

      res[k] = 0;
      is_used[i] = false;
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