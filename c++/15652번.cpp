#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];

void func(int k){ //
  if(k == M){
    for(int i = 0; i < M; i++) cout << arr[i] << " ";
    cout << "\n";
    return;
  }

  for(int i = 1; i <= N; i++){
    if(arr[k-1] <= i){
      arr[k] = i;
      func(k+1);
    }
  }
  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  func(0);


  return 0;
}