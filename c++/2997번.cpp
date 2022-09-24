#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> v(3);
  for(int i = 0, tmp; i < 3; i++){
    cin >> v[i]; 
  }

  sort(v.begin(), v.end());

  if(v[1] - v[0] != v[2] - v[1]){
    cout << v[0] + v[2] - v[1];
    return 0;
  }
  for(int i = 0; i < 2; i++){
    if(v[i] + (v[1] - v[0]) == v[i+1]) continue;
    else{
      cout << v[i] + (v[i] - v[0]);
      return 0;
    }
  }
  cout << v.back() + (v[1] - v[0]);
  return 0;
}