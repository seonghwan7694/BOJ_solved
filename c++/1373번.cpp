#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string str, tmp;
  cin >> str;
  while(str.size() % 3 != 0){
    str.insert(str.begin(), '0');
  }
  for(int i = 0; i < str.size(); i += 3){
    tmp = str.substr(i, 3);
    if(tmp == "000") cout << 0;
    if(tmp == "001") cout << 1;
    if(tmp == "010") cout << 2;
    if(tmp == "011") cout << 3;
    if(tmp == "100") cout << 4;
    if(tmp == "101") cout << 5;
    if(tmp == "110") cout << 6;
    if(tmp == "111") cout << 7;
  }
  return 0;
}