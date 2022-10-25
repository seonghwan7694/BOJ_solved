#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int t;
  cin >> t;
  while(t--){
    long int r, e, c;
    cin >> r >> e >> c;
    long int a = r, b = e - c;
    if(a == b){
      cout << "does not matter" << "\n";
    }else if(a > b){
      cout << "do not advertise" << "\n";
    }else if(a < b){
      cout << "advertise" << "\n";
    }
  }


  return 0;
}