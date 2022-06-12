#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int a, b, c; cin >> a >> b >> c;
  bool f1 = (a == b);
  bool f2 = (a == c);
  bool f3 = (b == c);
  if(a == 60 and b == 60 and c == 60) cout << "Equilateral";
  else if(a + b + c == 180 and (f1 or f2 or f3)) cout << "Isosceles";
  else if(a + b + c == 180) cout << "Scalene";
  else cout << "Error";

  return 0;
}