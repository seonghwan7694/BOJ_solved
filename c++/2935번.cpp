#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string A, B;
  char c;
  cin >> A >> c >> B;
  if(c == '*'){
    cout << '1';
    for(int i = 0; i < A.length() - 1 + B.length() - 1; i++){
      cout << '0';
    }
  }else{
    if(A.length() < B.length()) swap(A, B); // 항상 A.length > B.length
    if(A.length() == B.length()){
      A[0] = '2';
      cout << A;
      return 0;
    }
    while(A.length() != B.length()) B.insert(B.begin(), '0');
    for(int i = 0; i < A.length(); i++){
      if(A[i] == '1' or B[i] == '1') cout << '1';
      else cout << '0';
    }
  }
  return 0;
}