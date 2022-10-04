#include <bits/stdc++.h>
using namespace std;
string str, happy = ":-)", saad = ":-(";
int hap, sad;
bool flag;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  getline(cin, str);
  if(str.length() <= 2){
    cout << "none" << "\n";
    return 0;
  }
  for(int i = 0; i < str.length(); i++){
    if(happy == str.substr(i, 3)){ flag = true; hap++; }
    if(saad == str.substr(i, 3)){ flag = true; sad++; }
  }

  if(!flag){
    cout << "none" << "\n";
  }else if(hap == sad){
    cout << "unsure" << "\n";
  }else if(hap > sad){
    cout << "happy" << "\n";
  }else{
    cout << "sad" << "\n";
  }
  return 0;
}
