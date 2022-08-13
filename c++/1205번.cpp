#include <bits/stdc++.h>
using namespace std;

int N, score, P;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> score >> P;
  vector<pair<int, int>> v(N+1);
  for(int i = 0; i < N; i++){
    cin >> v[i].first;
  }
  v[N].first = score;

  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());

  v[0].second = 1;
  for(int i = 1; i < N+1; i++){
    v[i].second = i + 1;
    if(v[i-1].first == v[i].first) v[i].second = v[i-1].second;
  }

  for(int i = N; i >= 0; i--){
    if(v[i].first == score){ // i + 1등
      if(i + 1 > P) cout << -1 << "\n";
      else cout << v[i].second << "\n";
      break;
    }
  }

  return 0;
}