#include <bits/stdc++.h>
using namespace std;

int N, ans;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  vector<string> v(N);
  for(int i = 0; i < N; i++){
    cin >> v[i];
    for(int j = 0; j < v[i].length() - 1; j++){
      if(v[i][j] != v[i][j+1]) ans++;
    }
  }
  const int ori_ans = ans;
  ans = 987654321;
  sort(v.begin(), v.end());
  do{
    int tmp_ans = ori_ans;
    for(int i = 0; i < N - 1; i++){
      if(v[i].back() != v[i+1].front()) tmp_ans++;
    }
    ans = min(tmp_ans, ans);
  }while(next_permutation(v.begin(), v.end()));

  cout << ans << "\n";
  return 0;
}