#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  while(true){
    int n, m, l;
    cin >> n >> m >> l;
    if(n == 0 and m == 0 and l == 0) break;
    
    if(m < l) swap(m, l);
    if(m < n) swap(m ,n);
    if(m >= l + n){
      cout << "Invalid" << "\n";
      continue;
    }
    if(n == m and m == l and l == n){
      cout << "Equilateral" << "\n";
    }else if(n != m and m != l and l != n){
      cout << "Scalene" << "\n";
    }else{
      cout << "Isosceles" << "\n";
    }
  }


  return 0;
}