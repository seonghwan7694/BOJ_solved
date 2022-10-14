#include <bits/stdc++.h>
using namespace std;

int ans = -1, ans_i, ans_j, tmp;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  for(int i = 1; i <= 9; i++){
    for(int j = 1; j <= 9; j++){
      cin >> tmp;
      if(tmp > ans){
        ans = tmp;
        ans_i = i, ans_j = j;
      }
    }
  }
  cout << ans << "\n";
  cout << ans_i << " " << ans_j;

  return 0;
}