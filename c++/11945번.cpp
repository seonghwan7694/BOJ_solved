#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  string str;
  cin >> n >> m;
  while(n--){
    cin >> str;
    reverse(str.begin(), str.end());
    cout << str << "\n";
  }


  return 0;
}