#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  unordered_set<char> us;
  us.insert('a');
  us.insert('i');
  us.insert('e');
  us.insert('o');
  us.insert('u');
  string s;
  cin >> s;
  int ans = 0;
  for(auto& c : s){
    if(us.find(c) != us.end()) ans++;
  }
  cout << ans << "\n";
  return 0;
}