#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int arr[28]; fill(arr, arr + 28, 1);
  for(int i = 0, tmp; i < 26; i++){
    cin >> tmp;
    arr[tmp]--;
  }
  for(int i = 0; i < 28; i++){
    if(arr[i] == 1) cout << i << "\n";
  }
}