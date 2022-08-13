#include <bits/stdc++.h>
using namespace std;

int i, j;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string str;
  cin >> str;
  int a = 0, b = 0, ans = 0;
  for(; i < str.size(); i = j + 1){
    int cnt = 0;
    for(j = i; j < str.size(); j++){
      if(str[i] == str[j]) cnt++;
      else{
        j--;
        break;
      }
    }
    ans += 10;
    ans += 5 * (cnt - 1);
  }
  cout << ans << "\n";
  return 0;
}