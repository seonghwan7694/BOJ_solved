#include <bits/stdc++.h>
using namespace std;
int n;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  if(n == 0){
    cout << 0 << "\n";
    return 0;
  }

  string res;
  while(n != 0){
    if(n%-2 == 0){
      res += "0";
      n /= -2;
    }else{
      res += "1";
      n = (n-1)/-2;
    }
  }

  reverse(res.begin(), res.end());
  cout << res << "\n";
  return 0;
}