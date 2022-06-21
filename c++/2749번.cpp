#include <bits/stdc++.h>
using namespace std;

vector<long long> v;
long long idx = 2;

void pisano(long long mod){
  v.push_back(0);
  v.push_back(1);
  v.push_back(1);
  
  while(true){
    v.push_back((v[idx] + v[idx - 1])%mod);
    idx++;
    if(v[idx - 1] == 1 and v[idx - 0] == 0) break;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  long long n; cin >> n;
  pisano(1000000);

  cout << v[n%idx];
  return 0;
}