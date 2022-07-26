#include <bits/stdc++.h>
using namespace std;

vector<long long> ans;
int N;

void func(long long num){
  if(num % 10 == 0){
    while(num / 10 != 0){
      ans.push_back(num);
      num /= 10;
    }
    return;
  }

  for(int i = 9; i >= 0; i--){
    if((num % 10) > i){
      func(num * 10 + i);
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  // 9,876,543,210
  cin >> N;
  if(N >= 500000){
    cout << -1 << "\n";
    return 0;
  }
  ans = vector<long long>(5050505, 0);
  for(int i = 0; i < 10; i++){
    ans.push_back(i);
    func(i);
  }
  sort(ans.begin(), ans.end());
  auto iter = ans.begin();
  ans.erase((iter = unique(ans.begin(), ans.end())), ans.end());
  // 15, 16
  if(N-1 >= 1023){
    cout << -1 << "\n";
  }else{
    cout << ans[N-1] << "\n";
  }
  return 0;
}