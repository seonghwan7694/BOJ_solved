#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t, n;
  cin >> t;
  while(t--){
    cin >> n;
    vector<int> v(n, 0);
    for(int i = 0; i < n; i++){
      cin >> v[i];
    }
    cout << 2*(*max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end())) << "\n";
  }

  return 0;
}