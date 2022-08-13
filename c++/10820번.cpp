#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  string str;
  while(getline(cin, str)){
    int a = 0, b = 0, c = 0, d = 0;
    for(int i = 0; i < str.size(); i++){
      if('a' <= str[i] and str[i] <= 'z') a++;
      else if('A' <= str[i] and str[i] <= 'Z') b++;
      else if(str[i] == ' ') d++;
      else c++;
    }
    cout << a << " " << b << " " << c << " " << d << "\n";
  }


  return 0;
}