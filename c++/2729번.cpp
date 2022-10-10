#include <bits/stdc++.h>
using namespace std;

int t;

void solution(){
  string a, b, ans;
  cin >> a >> b;
  bool flag = false;
  reverse(a.begin(), a.end());
  while(a.back() == '0') a.erase(a.end() - 1);
  reverse(b.begin(), b.end());
  while(b.back() == '0') b.erase(b.end() - 1);

  if(a.length() < b.length()) swap(a, b); // a >= b;
  while(a.length() != b.length()) b.push_back('0');

  for(int i = 0; i < a.length(); i++){
    if(flag){
      if(a[i] == '0' and b[i] == '0'){
        ans.push_back('1');
        flag = false;
      }
      if(a[i] == '1' and b[i] == '0'){
        ans.push_back('0');
        flag = true;
      }
      if(a[i] == '0' and b[i] == '1'){
        ans.push_back('0');
        flag = true;
      }
      if(a[i] == '1' and b[i] == '1'){
        ans.push_back('1');
        flag = true;
      }
    }else{
      if(a[i] == '0' and b[i] == '0'){
        ans.push_back('0');
        flag = false;
      }
      if(a[i] == '1' and b[i] == '0'){
        ans.push_back('1');
        flag = false;
      }
      if(a[i] == '0' and b[i] == '1'){
        ans.push_back('1');
        flag = false;
      }
      if(a[i] == '1' and b[i] == '1'){
        ans.push_back('0');
        flag = true;
      }
    }
  }
  if(flag) ans.push_back('1');
  reverse(ans.begin(), ans.end());
  while(ans.front() == '0') ans.erase(ans.begin());

  if(ans.empty()) cout << "0" << "\n";
  else cout << ans << "\n";

}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while(t--){
    solution();
  }
  return 0;
}