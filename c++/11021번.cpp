#include <bits/stdc++.h>
using namespace std;

int test_case;
int a, b;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> test_case;
  for(int i = 1; i <= test_case; i++){
    cin >> a >> b;
    cout << "Case #" << i << ": " << a + b << "\n";
  }
  return 0;
}