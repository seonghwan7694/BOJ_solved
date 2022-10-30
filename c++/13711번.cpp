#include <bits/stdc++.h>
using namespace std;
#define MAX 101010
typedef long long int lld;
lld N, A[MAX], B[MAX], idx[MAX];
int main(){
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> A[i];
    idx[A[i]] = i;
  }
  vector<lld> ans;
  for(int i = 0; i < N; i++){
    cin >> B[i];
    B[i] = idx[B[i]];
    if(ans.empty() or ans.back() < B[i]) ans.push_back(B[i]);
    else{
      auto it = lower_bound(ans.begin(), ans.end(), B[i]);
      *it = B[i];
    }
  }
  cout << ans.size();
  return 0;
}