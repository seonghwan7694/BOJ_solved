#include <bits/stdc++.h>
using namespace std;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string str, ans; cin >> str;
  for(auto x : str){
    if('A' <= x and x <= 'Z') ans += x - 'A' + 'a';
    else ans += x - 'a' + 'A';
  }
  cout << ans;

  return 0;
}