#include <bits/stdc++.h>
using namespace std;

bool vowel[500];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  vowel['a'] = vowel['e'] = vowel['i'] = vowel['o'] = vowel['u'] = true;
  vowel['A'] = vowel['E'] = vowel['I'] = vowel['O'] = vowel['U'] = true;
  while(true){
    string str; getline(cin, str);
    if(str == "#") return 0;
    int ans = 0;
    for(auto ch : str) if(vowel[ch]) ans++;
    cout << ans << "\n";
  }


  return 0;
}