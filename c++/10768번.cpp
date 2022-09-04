#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  if(n == 2 and m == 18) cout << "Special";
  else if(n >= 2 and m > 18) cout << "After";
  else if(n > 2) cout << "After";
  else if(n <= 2 and m < 18) cout << "Before";
  else cout << "Before";

  


  return 0;
}