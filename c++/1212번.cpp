#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string str;
  cin >> str;
  string ans;
  if(str[0] == '0'){
    cout << 0 << "\n";
    return 0;
  }
  for(int i = 0; i < str.size(); i++){
    if(str[i] == '0') ans.append("000");
    else if(str[i] == '1') ans.append("001");
    else if(str[i] == '2') ans.append("010");
    else if(str[i] == '3') ans.append("011");
    else if(str[i] == '4') ans.append("100");
    else if(str[i] == '5') ans.append("101");
    else if(str[i] == '6') ans.append("110");
    else if(str[i] == '7') ans.append("111");
  }
  while(ans.front() == '0'){
    ans.erase(ans.begin());
  }
  cout << ans << "\n";


  return 0;
}