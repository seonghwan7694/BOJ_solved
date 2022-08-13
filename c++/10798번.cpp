#include <bits/stdc++.h>
using namespace std;
  char a[5][16];

int main(){
  for(int i = 0; i < 5; i++){
    cin >> a[i];
  }
  for(int i = 0; i < 15; i++){
    for(int j = 0; j < 5; j++){
      if(a[j][i] != '\0') cout << a[j][i];
    }
  }
  return 0;
}