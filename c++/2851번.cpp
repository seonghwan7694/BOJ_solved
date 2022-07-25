#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  vector<int> v(10);
  for(int i= 0; i < 10; i++){
    cin >> v[i];
  }
  for(int i = 1; i < 10; i++){
    v[i] += v[i-1];
  }
  auto iter1 = lower_bound(v.begin(), v.end(), 100);
  auto iter2 = prev(iter1, 1);
  if(abs(*iter1 - 100) == abs(*iter2 - 100)){
    cout << max(*iter1, *iter2) << "\n";
  }else if(abs(*iter1 - 100) > abs(*iter2 - 100)){
    cout << *iter2 << "\n";
  }else{
    cout << *iter1 << "\n";
  }
  return 0;
}