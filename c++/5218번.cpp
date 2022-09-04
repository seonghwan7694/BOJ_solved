#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while(tc--){
    string a, b;
    cin >> a >> b;
    cout << "Distances: ";
    for(int i = 0; i < a.length(); i++){
      if(b[i] >= a[i]){
        cout << (int) (b[i] - 'A' + 1) - (a[i] - 'A' + 1) << " ";
      }else{
        cout << (int) (b[i] - 'A' + 1) + 26 - (a[i] - 'A' + 1) << " ";
      }
    }
    cout << "\n";
  }
}