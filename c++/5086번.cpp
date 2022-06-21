#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  while(true){
    int a, b; cin >> a >> b;
    if(!a and !b) break;

    if(b % a == 0 and a < b) cout << "factor" << "\n";
    else if(a % b == 0 and a > b) cout << "multiple" << "\n";
    else{
      cout << "neither" << "\n";
    }
  }
  return 0;
}