#include <bits/stdc++.h>
using namespace std;

int N, T, n, m, st, en;
bool arr[101];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  for(int i = 1; i <= N; i++){
    cin >> arr[i];
  }
  cin >> T;
  while(T--){
    cin >> n >> m;
    if(n == 1){
      for(int i = m; i <= N; i += m){
        arr[i] = !arr[i];
      }
    }else{
      st = m, en = m;
      while(st - 1 >= 1 and en + 1 <= N){
        if(arr[st - 1] == arr[en + 1]){
          st--;
          en++;
        }else{
          break;
        }
      }
      for(int i = st; i <= en; i++){
        arr[i] = !arr[i];
      }
    }
  }

  for(int i = 1; i <= N; i++){
    cout << arr[i];
    if(i % 20 == 0 and i > 10) cout << "\n";
    else cout << " ";
  }
  return 0;
}