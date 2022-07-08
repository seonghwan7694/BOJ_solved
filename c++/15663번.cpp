#include <bits/stdc++.h>
using namespace std;

int N, M, xx;
int arr[10];
int res[10];
bool is_used[10];

void func(int k){ // 현재까지 k개를 선택하였습니다.
  if(k == M){ // M개를 선택하면 출력합니다.
    for(int i = 0; i < M; i++){
      cout << res[i] << " ";
    }
    cout << "\n";
    return;
  }

  int xx = 0;

  for(int i = 0; i < N; i++){
    if(!is_used[i] and arr[i] != xx){
      is_used[i] = true;
      res[k] = arr[i];
      xx = res[k];
      func(k + 1);
      res[k] = 0;
      is_used[i] = false;
    }
  }

  return;
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