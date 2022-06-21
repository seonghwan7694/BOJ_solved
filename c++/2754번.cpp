#include <bits/stdc++.h>
using namespace std;

double get_value(char c){
  if(c == '+') return 0.3;
  if(c == '-') return -0.3;
  return 0.0;
}
int main(){
  ios::sync_with_stdio(false);
  cout.tie(0); cin.tie(0);
  cout << fixed; cout.precision(1);
  string str; cin >> str;
  if(str[0] == 'F'){
    cout << 0.0;
    return 0;
  }
  cout << (('E' - str[0]) + get_value(str[1])); 
  return 0;
}