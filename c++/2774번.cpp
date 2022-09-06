#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    bool vis[11] = {false};
    int ans = 0;
    string str;
    cin >> str;
    for(int i = 0; i < str.length(); i++){
      if(!vis[str[i] - '0']){
        ans++;
        vis[str[i] - '0'] = true;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}