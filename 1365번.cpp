#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> v;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;
  v.push_back(0);
  for(int i = 0, num; i < N; i++){
    cin >> num;
    if(num > v.back()){
      v.push_back(num);
    }else{
      int idx = lower_bound(v.begin(), v.end(), num) - v.begin();
      v[idx] = num;
    }
  }
  cout << N - (v.size() - 1);



  return 0;
}