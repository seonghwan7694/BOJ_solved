#include <bits/stdc++.h>
using namespace std;

int N, B;
string chk = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string ans;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> B;
  while(N){
    ans.push_back(chk[N%B]);
    N /= B;
  }
  reverse(ans.begin(), ans.end());
  cout << ans;
  return 0;
}