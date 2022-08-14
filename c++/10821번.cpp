#include <bits/stdc++.h>
using namespace std;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  int ans = 1;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == ',') ans++;
  }

  cout << ans << "\n";

  return 0;
}