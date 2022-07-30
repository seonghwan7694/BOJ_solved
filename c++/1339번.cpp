#include <bits/stdc++.h>
using namespace std;

int N;
string str[10];
int alphabet[26];
long long ans;
int val[26];
unordered_set<char> s;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;

  for(int i = 0; i < N; i++){
    cin >> str[i];
    for(int j = 0; j < str[i].length(); j++){
      alphabet[str[i][j] - 'A'] += pow(10, str[i].length() - j - 1);
      s.insert(str[i][j]);
    }
  }

  int cnt = s.size();
  int number = 9;
  while(cnt--){
    int idx = max_element(alphabet, alphabet + 26) - alphabet;
    val[idx] = number--;
    *(alphabet + idx) = -1;
  }
  
  for(int i = 0; i < N; i++){
    for(int j = 0; j < str[i].length(); j++){
      ans += val[str[i][j] - 'A'] * pow(10, str[i].length() - j - 1);
    }
  }
  cout << ans << "\n";






  return 0;
}