#include <bits/stdc++.h>
using namespace std;

int N, ans = 0;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  vector<int> v(N);
  for(int i = 0; i < N; i++){
    cin >> v[i];
  }

  for(int i = 0; i < N; i++){
    for(int j = i + 1; j < N; j++){
      if(v[j-1] < v[j]){
        ans = max(v[j] - v[i], ans);
      }else{
        break;
      }

    }
  }
  cout << ans << "\n";

  return 0;
}