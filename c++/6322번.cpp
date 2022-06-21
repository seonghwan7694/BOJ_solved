#include <bits/stdc++.h>
using namespace std;

bool is_possible(int *s, bool p){
  int res = s[2] - s[!p];
  if(res <= 0){
    return false;
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cout << fixed;
  cout.precision(3);
  int test_case = 1;
  while(true){
    int s[3];
    cin >> s[0] >> s[1] >> s[2];
    if(s[0] == 0 and s[1] == 0 and s[2] == 0) break;
    cout << "Triangle #" << test_case++ << "\n";
    
    if(s[2] == -1){
      cout << "c = " << sqrt((double) s[0]*s[0] + s[1]*s[1]) << "\n\n";
    }else if(s[1] == -1){
      if(is_possible(s, 1)){
        cout << "b = " << sqrt((double) s[2]*s[2] - s[0]*s[0]) << "\n\n";
      }else{
        cout << "Impossible." << "\n\n";
      }
    }else if(s[0] == -1){
      if(is_possible(s, 0)){
        cout << "a = " << sqrt((double) s[2]*s[2] - s[1]*s[1]) << "\n\n";
      }else{
        cout << "Impossible." << "\n\n";
      }
    }
  }



  return 0;
}