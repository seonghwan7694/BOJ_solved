#include <bits/stdc++.h>
using namespace std;

string a, b;
int ans;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> a >> b;
  if(a.length() < b.length()) swap(a, b); // a >= b

  for(int i = 0; i <= a.length() - b.length(); i++){
    int tmp_ans = 0;
    for(int j = i; j < i + b.length(); j++){
      if(a[j] == b[j - i]) tmp_ans++;
    }
    ans = max(ans, tmp_ans);
  }
  cout << b.length() - ans << "\n";
  return 0;
}