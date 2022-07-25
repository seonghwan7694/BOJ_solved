#include <bits/stdc++.h>
using namespace std;

int N, W, H, l;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> W >> H;
  double p = sqrt(W*W + H*H);
  while(N--){
    cin >> l;
    if(l <= p) cout << "DA" << "\n";
    else cout << "NE" << "\n";
  }



  return 0;
}