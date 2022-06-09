#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N; cin >> N;
  set<string> s;
  while(N--){
    string name, state; cin >> name >> state;
    if(state == "enter"){
      s.insert(name);
    }else{
      s.erase(name);
    }
  }
  vector<string> ans(s.begin(), s.end());
  sort(ans.begin(), ans.end(), greater<string>());
  for(auto x : ans) cout << x << "\n";
  return 0;
}