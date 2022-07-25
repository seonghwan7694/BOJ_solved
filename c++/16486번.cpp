#include <bits/stdc++.h>
using namespace std;
#define M_PI 3.14159265358979323846

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cout << fixed;
  cout.precision(6);
  long d1, d2;
  cin >> d1 >> d2;
  
  cout << d1 * 2 + (2 * M_PI * d2) << "\n";

  return 0;
}