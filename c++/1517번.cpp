#include <bits/stdc++.h>
using namespace std;

#define MAX_N 505050
long long A[MAX_N];
int N;
long long ans;
long long tmp[MAX_N];

void merge(int left, int mid, int right){
  int i = left, j = mid + 1, k = left;
  while(i <= mid and j <= right){
    if(A[i] <= A[j]){
      tmp[k] = A[i];
      i++;
    }else{
      tmp[k] = A[j];
      ans += j - k;
      j++;
    }
  }

  if(i > mid){
    for(int x = j; j <= right; x++){
      tmp[k++] = A[x];
    }
  }else{
    for(int x = i; x <= mid; x++){
      tmp[k++] = A[x];
    }
  }
  for(int x = left; x <= right; x++){
    A[x] = tmp[x];
  }
  return;
}

void merge_sort(int left, int right){
  if(left >= right) return;
  int mid = (left + right) >> 1;
  merge_sort(left, mid);
  merge_sort(mid + 1, right);
  merge(left, mid, right);
}
int main(){
  ios::sync_with_stdio(false);
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }
  merge_sort(0, N - 1);
  cout << ans << "\n";
  return 0;
}