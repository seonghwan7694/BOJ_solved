#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, M;
  cin >> N >> M;
  stringstream ss;
  ss << N;
  string s = ss.str();
  while(N--){
    for(int i = 0; i < s.length(); i++){
      cout << s[i];
      if(!(--M)) return 0;
    }
  }

  return 0;
}