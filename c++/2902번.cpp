#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string input, ans;
  cin >> input;
  for(int i = 0; i < input.size(); i++){
    if('A' <= input[i] and input[i] <= 'Z') ans.push_back(input[i]);
  }
  cout << ans << "\n";
  return 0;
}