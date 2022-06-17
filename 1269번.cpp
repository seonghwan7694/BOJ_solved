#include <bits/stdc++.h>
using namespace std;

set<int> A;
set<int> B;
int a, b, res;

int solution(set<int> &a, set<int> &b){ // a - b
  int ans = 0;
  for(auto iter : a){
    if(b.find(iter) == b.end()) ans++;
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> a >> b;
  for(int i = 0; i < a; i++){ int tmp; cin >> tmp; A.insert(tmp); };
  for(int i = 0; i < b; i++){ int tmp; cin >> tmp; B.insert(tmp); };
  res += solution(A, B);
  res += solution(B, A);
  cout << res << "\n";
  return 0;
}