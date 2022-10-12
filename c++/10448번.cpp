#include <bits/stdc++.h>
using namespace std;

int t, k, T[50];

bool solution(){

  cin >> k;
  for(int i = 1; i < 50; i++){
    for(int j = i; j < 50; j++){
      for(int l = j; l < 50; l++){
        if(T[i] + T[j] + T[l] == k) return true;
      }
    }
  }

  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> t;
  for(int i = 1; i < 50; i++){
    T[i] = i*(i+1)/2;
  }
  while(t--){
    cout << (solution() ? '1' : '0') << "\n";
  }


  return 0;
}