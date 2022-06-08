#include <bits/stdc++.h>
using namespace std;

int arr[101010];
int N, M;
int ans = 0x7fffffff;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  for(int i = 0; i < N; i++){
    cin >> arr[i];
  }

  sort(arr, arr + N); // 오름차순 정렬
  
  int st = 0, en = 0;
  while(true){
    int delta = arr[en] - arr[st];
    while(delta < M){
      delta = arr[++en] - arr[st];
      if(en >= N){
        cout << ans;
        return 0;
      }
    }
    ans = min(delta, ans); st++;
  }
  cout << ans;
  return 0;
}