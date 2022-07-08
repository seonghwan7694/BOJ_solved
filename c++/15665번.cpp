#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
int res[10];
void func(int k){
  if(k == M){
    for(int i = 0; i < M; i++){
      cout << res[i] << " ";
    }
    cout << "\n";
    return;
  }
  
  int xx = 0;
  for(int i = 0; i < N; i++){
    if(arr[i] != xx){
      res[k] = arr[i];
      xx = arr[i];
      func(k+1);
      res[k] = 0;
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