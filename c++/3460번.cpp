#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t, c;
  cin >> t;
  while(t--){
    cin >> c;
    vector<int> v;
    int cnt = 0;
    while(c != 0){
      if(c % 2 == 1) v.push_back(cnt);
      c /= 2; cnt++;
    }
    for(auto& x : v){
      cout << x << " ";
    }
    cout << "\n";
  }
  return 0;
}