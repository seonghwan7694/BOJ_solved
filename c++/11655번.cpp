#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string str;
  getline(cin, str);

  for(int i = 0; i < str.size(); i++){
    if(str[i] == ' ') cout << ' ';
    else if('0' <= str[i] and str[i] <= '9') cout << str[i];
    else{
      if('a' <= str[i] and str[i] <= 'z'){
        if((str[i] + 13) > 'z') cout << (char) ((str[i] + 13)%'z' + 'a' - 1);
        else cout << (char) (str[i] + 13);
      }
      else{
        if((str[i] + 13) > 'Z') cout << (char) ((str[i] + 13)%'Z' + 'A' - 1);
        else cout << (char) (str[i] + 13);
      }
    }
  }

  return 0;
}