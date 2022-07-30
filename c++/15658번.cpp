#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int N;
int A[11];
int op[4];
int MAX = -INF, MIN = INF;

void func(int k, int val){
  if(k == N){
    MAX = max(MAX, val);
    MIN = min(MIN, val);
    return;
  }

  for(int i = 0; i < 4; i++){
    if(op[i] != 0){
      op[i]--;
      if(i == 0) func(k + 1, val + A[k]);
      else if(i == 1) func(k + 1, val - A[k]);
      else if(i == 2) func(k + 1, val * A[k]);
      else if(i == 3) func(k + 1, val / A[k]);
      op[i]++;
    }
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }
  for(int i = 0; i < 4; i++){
    cin >> op[i];
  }

  func(1, A[0]);
  cout << MAX << "\n";
  cout << MIN << "\n";



  return 0;
}