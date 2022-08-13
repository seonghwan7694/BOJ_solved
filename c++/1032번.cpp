#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N; cin >> N;
  vector<string> v(N);
  for(int i = 0; i < N; i++){
    cin >> v[i];
  }
  string ans;
  for(int i = 0; i < v[0].size(); i++){
    int alpha = 0, dot = 0;
    bool diff = false;
    for(int j = 0; j < N; j++){
      if(v[j][i] == '.') dot++;
      else{
        if(v[0][i] != v[j][i]){
          ans.push_back('?');
          diff = true;
          break;
        }
        alpha++;
      }
    }
    if(diff) continue;
    if(dot == N) ans.push_back('.');
    else if(dot > 0) ans.push_back('?');
    else ans.push_back(v[0][i]);
  }

  cout << ans << "\n";
  return 0;
}