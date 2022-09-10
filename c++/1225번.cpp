#include <bits/stdc++.h>
using namespace std;


long long ans;
string N, M;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;

  for(int i = 0; i < N.length(); i++){
    for(int j = 0; j < M.length(); j++){
      ans += (N[i] - '0') * (M[j] - '0');
    }
  }
  cout << ans << "\n";
  return 0;
}