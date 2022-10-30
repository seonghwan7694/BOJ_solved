#include <bits/stdc++.h>
using namespace std;
#define MAX 500000
typedef long long int lld;
vector<lld> arr(MAX+1, 0), sorted_arr(MAX+1, 0);
lld N, ans;

void merge(int left, int mid, int right){
  int i, j, k, l;
  i = left;
  j = mid + 1;
  k = left;

  while(i <= mid && j <= right){
    if(arr[i] <= arr[j]) sorted_arr[k++] = arr[i++];
    else{
      ans += (lld) mid - i + 1;
      sorted_arr[k++] = arr[j++];
    }
  }

  if(i > mid){
    for(l = j; l <= right; l++){
      sorted_arr[k++] = arr[l];
    }
  }else{
    for(l = i; l <= mid; l++){
      sorted_arr[k++] = arr[l];
    }
  }

  for(l=left; l<=right; l++){
    arr[l] = sorted_arr[l];
  }
}

void merge_sort(int left, int right){
  int mid;
  if(left < right){
    mid = (left + right)/2;
    merge_sort(left, mid);
    merge_sort(mid+1, right);
    merge(left, mid, right);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> arr[i];
  }
  merge_sort(0, N-1);
  cout << ans << "\n";
  return 0;
}