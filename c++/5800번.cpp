#include <bits/stdc++.h>
using namespace std;
int cnt = 1;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  while(tc--){
    int a = -987654321, b = 987654321, c = -987654321;
    int n; cin >> n;
    vector<int> input;
    while(n--){
      int tmp; cin >> tmp;
      input.push_back(tmp);
    }
    a = *max_element(input.begin(), input.end());
    b = *min_element(input.begin(), input.end());
    sort(input.begin(), input.end());
    for(int i = 0; i < input.size() - 1; i++){
      c = max(c, input[i+1] - input[i]);
    }
    cout << "Class " << cnt++ << "\n"; 
    cout << "Max " << a << ", Min " << b << ", Largest gap " << c << "\n";
  }

  return 0;
}