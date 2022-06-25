#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string str; cin >> str;
  if(str == "1010"){
    cout << 20;
    return 0;
  }
  if(str.size() == 2){
    cout << str[0] - '0' + str[1] - '0';
  }else if(str[1] == '0'){
    cout << (str[0] - '0')*10 + str[2] - '0';
  }else{
    cout << str[0] - '0' + (str[1] - '0')*10;
  }


  return 0;
}