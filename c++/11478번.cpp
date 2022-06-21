#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  
  set<string> s;
  string str, tmp; cin >> str;
  /*
  for(int i = 1; i <= str.length(); i++){ // str의 부분문자열 원소 i개를 추출한다.
    for(int j = 0; j + i - 1 < str.length(); j++){ // str[j] ~ str[j + i - 1] 개를 tmp 변수에 담는다.
      string tmp; tmp.clear();
      for(int k = j; k < j + i; k++){
        tmp += str[k];
      }
      s.insert(tmp);
    }
  }
  */
  for (int i = 0; i < str.size(); i++) {
    for (int j = i; j < str.size(); j++) {
        tmp += str[j];
        s.insert(tmp);
    }
    tmp = "";
  }
  cout << s.size() << "\n";
  return 0;
}