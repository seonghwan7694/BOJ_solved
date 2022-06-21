#include <bits/stdc++.h>
using namespace std;

int P[50];
pair<int,int> A[50];
int B[50];
int N;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;
  for(int i = 0, tmp; i < N; i++){
    cin >> tmp;
    A[i] = {tmp, i};
  }
  sort(A, A + N);
  for(int i = 0; i < N; i++){
    B[A[i].second] = i;
  }
  for(int i = 0; i < N; i++){
    cout << B[i] << " ";
  }

  
  return 0;
}