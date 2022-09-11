#include <bits/stdc++.h>
using namespace std;
int val[101];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  fill(val, val + 101, 3); val['0'] = 4; val['1'] = 2;
  string s;
  while(true){
    cin >> s;
    if(s == "0") break;
    int ans = s.length() + 1;
    for(int i = 0; i < s.length(); i++){
      ans += val[s[i]];
    }
    cout << ans << '\n';
  }
  return 0;
}