#include <bits/stdc++.h>
using namespace std;

int N, K, MAX = -0x7fffffff;
vector<int> v(101010);

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> K;
  for(int i = 1; i <= N; i++){
    int tmp; cin >> tmp;
    v[i] = v[i-1] + tmp;
  }
  for(int i = K; i <= N; i++){
    MAX = max(MAX, v[i] - v[i-K]);  // [0 ~ i] - [0 ~ i-K] = i - (i - K) + 1 = K + 1
  }
  cout << MAX << "\n";
  return 0;
}