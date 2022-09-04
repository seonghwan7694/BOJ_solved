#include <bits/stdc++.h>
using namespace std;
vector<int> cache(1e6 + 1, 0);

int main(){
  int T;
  cin >> T;
  cache[0] = 1;
  for(int i = 1; i < 1e6 + 1; i++){
    stringstream ss;
    string s;
    ss << i;
    s = ss.str();
    for(auto& c : s){
      if(c == '0') cache[i]++;
    }
    cache[i] += cache[i-1];
  }

  while(T--){
    int N, M;
    cin >> N >> M;
    if(N != 0) cout << cache[M] - cache[N-1] << "\n";
    if(N == 0) cout << cache[M] << "\n";
    
  }
}