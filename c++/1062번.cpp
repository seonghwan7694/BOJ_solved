#include <bits/stdc++.h>
using namespace std;

int N, K, ans;
vector<string> word;
string tmp;
bool alphabet[26];

int can_read(){
  int cnt = 0, res = 0;
  for(auto str : word){
    for(int i = 0; i < str.length(); i++){
      if(alphabet[str[i] - 'a']) cnt++;
    }
    if(cnt == str.length()) res++;
    cnt = 0;
  }
  return res;
}

void func(int l, int k){ // 이전에 고른 알파벳은 l이며, k개의 글자를 읽을수 있습니다.
  if(k > K) return;
  if(k == K){
    ans = max(ans, can_read());
  }
  for(int i = l; i < 26; i++){
    if(!alphabet[i]){
      alphabet[i] = true;
      func(i, k + 1);
      alphabet[i] = false;
    }
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> N >> K;
  while(N--){
    cin >> tmp;
    word.push_back(tmp);
  }
  alphabet['a' - 'a'] = true;
  alphabet['n' - 'a'] = true;
  alphabet['t' - 'a'] = true;
  alphabet['i' - 'a'] = true;
  alphabet['c' - 'a'] = true;
  func(0, 5);
  cout << ans << "\n";
  return 0;
}