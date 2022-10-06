#include <bits/stdc++.h>
using namespace std;
int n, m;
string str;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> str;
  n = 1, m = str.length();
  for(int i = 1; i <= str.length(); i++){
    if(str.length()%i == 0 and i <= str.length()/i){
      if(n < i){
        n = i;
        m = str.length()/i;
      }
    }
  }
  cout << n << " " << m << "\n";
  string::iterator iter = str.begin();
  vector<vector<int>> v(n, vector<int>(m));
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      v[j][i] = *iter;
      iter++;
    }
  }
  for(auto &vv : v){
    for(auto &vvv : vv){
      cout << (char) vvv;
    }
  }

  return 0;
}