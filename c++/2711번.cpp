#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t, r;
  cin >> t;
  string s;
  while(t--){
    cin >> r;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
      if(i == r - 1) continue;
      cout << s[i];
    }
    cout << "\n";
  }

  return 0;
}