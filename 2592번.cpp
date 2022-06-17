#include <bits/stdc++.h>
using namespace std;

int sum, MAX;
int freq[1010];
int main(){
  ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);

  for(int i = 0; i < 10; i++){
    int tmp; cin >> tmp;
    sum += tmp;
    freq[tmp]++;
  }
  cout << sum/10 << "\n";
  cout << max_element(freq, freq + 1010) - freq << "\n";
  return 0;
}