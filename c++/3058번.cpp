#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    int a = 0, b = 987654321, seven = 7;
    while(seven--){
      int tmp;
      cin >> tmp;
      if(tmp % 2 == 0){
        a += tmp;
        b = min(b, tmp);
      }
    }
    cout << a << " " << b << "\n";
  }


  return 0;
}