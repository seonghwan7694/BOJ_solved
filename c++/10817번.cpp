#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int arr[3]; cin >> arr[0] >> arr[1] >> arr[2];
  *max_element(arr, arr + 3) = 0;
  cout << *max_element(arr, arr + 3);

  return 0;
}