#include <bits/stdc++.h>
using namespace std;

int ans, X;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> X;
  for(int i = 0; i <= 8; i++){
    if(X & (1 << i)) ans++;
  }
  cout << ans;
  return 0;
}