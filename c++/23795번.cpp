#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, res;
int main(){
  while(true){
    cin >> n;
    if(n == -1) break;
    res += n;
  }
  cout << res << "\n";
}