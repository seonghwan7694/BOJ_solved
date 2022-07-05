#include <bits/stdc++.h>
using namespace std;

double a, b;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> a >> b;

  if(a * (1 - 0.01*b) >= 99.999999){
    cout << 0;
  }else{
    cout << 1;
  }

  return 0;
}