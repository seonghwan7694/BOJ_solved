#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int a, b, c; cin >> a >> b >> c;
  if(a + b + c >= 100){
    cout << "OK";
  }else{
    int tmp = min({a, b, c});
    if(a == tmp){
      cout << "Soongsil";
    }else if(b == tmp){
      cout << "Korea";
    }else{
      cout << "Hanyang";
    }
  }


  return 0;
}