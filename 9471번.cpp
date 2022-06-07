#include <bits/stdc++.h>
using namespace std;

int pisano(int mod){
  vector<int> v;
  int idx = 2;
  v.push_back(0);
  v.push_back(1);
  v.push_back(1);
  
  while(true){
    idx++;
    v.push_back((v[idx - 1] + v[idx - 2])%mod);
    if(v[idx - 1] == 0 and v[idx - 0] == 1) break;
  }
  return idx - 1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int test_case, num, mod; cin >> test_case;
  while(test_case--){
    cin >> num >> mod;
    cout << num << " " << pisano(mod) << "\n";
  }


  return 0;
}