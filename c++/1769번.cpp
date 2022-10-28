#include <bits/stdc++.h>
using namespace std;

string n;
int cnt;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  while(n.length() != 1){
    int sum = 0;
    for(int i = 0; i < n.length(); i++){
      sum += n[i] - '0';
    }
    n = to_string(sum);
    cnt++;
  }
  cout << cnt << "\n";
  switch(stoi(n)){
    case 3 : case 6 : case 9 :
      cout << "YES" << "\n";
      break;
    default :
      cout << "NO" << "\n";
      break;
  }
  return 0;
}