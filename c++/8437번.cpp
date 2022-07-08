#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int n, m; cin >> n >> m;
  int tmp = n/2 + m/2;
  cout << tmp << "\n" << n - tmp << "\n";
  return 0;
}