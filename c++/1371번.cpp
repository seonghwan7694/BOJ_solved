#include <bits/stdc++.h>
using namespace std;

string str;
int alphabet[26];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  while(getline(cin, str)){
    for(auto& c : str){
      alphabet[c - 'a']++;
    }
  }
  int ans = *max_element(alphabet, alphabet + 26);
  for(int i = 0; i < 26; i++){
    if(alphabet[i] == ans) cout << (char) (i + 'a');
  }

  return 0;
}