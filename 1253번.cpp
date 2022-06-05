#include <bits/stdc++.h>
using namespace std;

int N, res, cnt;
int arr[2020];
set<int> s;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> arr[i];
    if(arr[i] == 0) cnt++;
  }
  if(cnt == N){
    cout << N;
    return 0;
  }
  sort(arr, arr + N);

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      int idx = lower_bound(arr, arr + N, arr[i] - arr[j]) - arr;
      if(idx == i or idx == j or i == j) continue;
      if(arr[idx] + arr[j] == arr[i]){
        res++; break;
      }
    }
  }
  cout << res;
  
  return 0;
}