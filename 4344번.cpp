#include <bits/stdc++.h>
using namespace std;

int test_case, n, cnt, mean;
int arr[1010];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cout << fixed;
  cout.precision(3);

  cin >> test_case;
  while(test_case--){ cnt = 0, mean = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
      cin >> arr[i];
      mean += arr[i];
    }
    mean /= n;
    for(int i = 0; i < n; i++){
      if(arr[i] > mean) cnt++;
    }
    cout << cnt / (double) n * 100 << "%\n";
  }
  return 0;
}