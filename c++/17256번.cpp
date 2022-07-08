#include <bits/stdc++.h>
using namespace std;
int ax, ay, az;
int cx, cy, cz;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> ax >> ay >> az;
  cin >> cx >> cy >> cz;
  cout << cx - az << " " << cy/ay << " " << cz - ax; 

  return 0;
}