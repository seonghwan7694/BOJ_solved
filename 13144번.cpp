#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll N, res;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;
  vector<int> arr(N);
  vector<bool> chk(101010);
  for(int i = 0; i < N; i++){
    cin >> arr[i];
  }
  int en = 0; chk[arr[0]] = 1;
  for(int st = 0; st < N; st++){
    while(en < N - 1 and !chk[arr[en+1]]){
      en++;
      chk[arr[en]] = 1;
    }
    res += (en-st+1);
    chk[arr[st]] = 0;
  }

  cout << res;
  return 0;
}