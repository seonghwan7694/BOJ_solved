#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n;
  while(true){
    cin >> m;
    if(m == 0) return 0;
    if(m % n != 0){
      cout << m << " " << "is NOT a multiple of " << n << ".\n";
    }else{
      cout << m << " " << "is a multiple of " << n << ".\n";
    }
  }

  return 0;
}