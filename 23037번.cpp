#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  string str; cin >> str;
  int result = 0;
  for(int i = 0; i < str.length(); i++){
    result += (int) pow((str[i] - '0'),5);
  }
  cout << result;
}