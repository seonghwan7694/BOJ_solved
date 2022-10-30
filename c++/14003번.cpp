#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000 + 1000
typedef long long int lld;
lld N, len;
lld arr[MAX], L[MAX], P[MAX];

void backtrace(lld idx, lld num){
  if(idx == 0) return;
  if(P[idx] == num){
    backtrace(idx - 1, num - 1);
    cout << arr[idx] << " ";
  }else{
    backtrace(idx - 1, num);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  for(lld i = 1; i <= N; i++){
    cin >> arr[i];
    auto pos = lower_bound(L + 1, L + len + 1, arr[i]);
    *pos = arr[i];
    P[i] = distance(L, pos);
    if(pos == L + len + 1) len++;
  }
  cout << len << "\n";
  backtrace(N, len);
  return 0;
}