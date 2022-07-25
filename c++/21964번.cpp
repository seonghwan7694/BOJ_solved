#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  int N;
  string str;
  cin >> N >> str;
  string tmp(prev(str.end(), 5), str.end());
  cout << tmp << "\n";
  return 0; 
}