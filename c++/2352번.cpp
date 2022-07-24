#include <bits/stdc++.h>
using namespace std;

int n;
int arr[40001], lis[40001];

int binarysearch(int left, int right, int target){
  int mid;
  while(left < right){
    mid = (left + right)/2;
    if(lis[mid] < target){
      left = mid + 1;
    }else{
      right = mid;
    }
  }
  return right;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  int j = 0;
  lis[0] = arr[0];
  int i = 1;
  while(i < n){
    if(lis[j] < arr[i]){
      lis[j+1] = arr[i];
      j += 1;
    }else{
      int idx = binarysearch(0, j, arr[i]);
      lis[idx] = arr[i];
    }
    i += 1;
  }
  cout << j + 1;
  return 0;
}