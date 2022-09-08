#include <bits/stdc++.h>
using namespace std;
string input_one;
int input_two, input_three;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  while(true){
    cin >> input_one >> input_two >> input_three;
    if(input_one == "#" and input_two == 0 and input_three == 0) break;
    if(input_two > 17 or input_three >= 80){
      cout << input_one << " " << "Senior" <<  "\n";
    }else{
      cout << input_one << " " << "Junior" <<  "\n";
    }
  }


  return 0;
}