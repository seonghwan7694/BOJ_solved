#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> arr;
vector<int> sarr;
map<int, int> m;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  arr = vector<pair<int, int>>(N);
  sarr = vector<int>(N);

  for(int i = 0, A, B; i < N; i++){
    cin >> A >> B;
    arr[i] = {A, B};
    m[B] = A;
  }
  sort(arr.begin(), arr.end());
  for(int i = 0; i < N; i++){
    sarr[i] = arr[i].second;
  }

  vector<int> v;
  vector<int> iarr;
  for(int i = 0; i < N; i++){ 
    if(i == 0){
      v.push_back(sarr[i]);
      iarr.push_back(1);
      continue;
    }
    int idx = lower_bound(v.begin(), v.end(), sarr[i]) - v.begin();
    int len = v.size();
    if(idx == len) v.push_back(sarr[i]);
    else v[idx] = sarr[i];
    iarr.push_back(idx + 1);
  }
  int len = v.size();
  vector<int> ans(len);
  for(int i = N - 1, n = len; i >= 0; i--){
    if(iarr[i] == n) ans[--n] = sarr[i];
  }
  for(int i = 0; i < len; i++){
    m[ans[i]] = -1;
  }
  cout << N - len << "\n";
  for(int i = 0; i < N; i++){
    if(m[sarr[i]] == -1) continue;
    cout << m[sarr[i]] << " ";
  }



  return 0;
}