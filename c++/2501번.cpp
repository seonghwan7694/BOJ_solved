#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, K, cnt = 0;
  cin >> N >> K;
  vector<int> vis(N + 1, 0);
  for(int i = 1; i <= N; i++){
    if(N % i == 0) vis[++cnt] = i;
  }

  cout << vis[K] << "\n";
  return 0;
}