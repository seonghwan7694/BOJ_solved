#include <bits/stdc++.h>
using namespace std;

string str;
int sum;
bool zero = false;
bool check(){
  if(str.back() == '0'){
    return 1;
  }
  return 0;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> str;

  sort(str.rbegin(), str.rend());
  for(int i = 0; i < str.length(); i++){
    sum += str[i] - '0';
    if(str[i] == '0') zero = true;
  }
  if(sum % 3 == 0 and zero){
    do{
      if(check()){
        cout << str << "\n";
        return 0;
      }
    }while(prev_permutation(str.begin(), str.end()));
  }
  cout << -1 << "\n";
  return 0;
}