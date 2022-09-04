#include <bits/stdc++.h>
using namespace std;
long long n, m, ans;

pair<long long, long long> cal(long long x){
  long long two = 0, five = 0;
  for(long long i = 2; i <= x; i *= 2){
    two += x/i;
  }
  for(long long i = 5; i <= x; i *= 5){
    five += x/i;
  }
  return {two, five};
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  auto c_n = cal(n);
  auto c_nm = cal(n - m);
  auto c_m = cal(m);
  auto a = c_n.first - (c_nm.first + c_m.first);
  auto b = c_n.second - (c_nm.second + c_m.second);
  cout << min(a, b) << "\n";
  return 0;
}