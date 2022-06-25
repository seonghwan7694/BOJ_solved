#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  while(true){
    int a, b; cin >> a >> b;
    if(!a and !b) break;
    if(a > b){
      cout << "Yes" << "\n";
    }else{
      cout << "No" << "\n";
    }
  }


  return 0;
}