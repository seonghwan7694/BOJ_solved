#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int K;
  cin >> K;
  while(K--){
    int P, M;
    cin >> P >> M;
    bool chk[505] = {false}; int ans = 0;
    while(P--){
      int tmp;
      cin >> tmp;
      if(!chk[tmp]) chk[tmp] = true;
      else ans++;
    }
    cout << ans << "\n";
  }

  return 0;
}