#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int N, ans;
int a[55][55];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;
  for(int i = 0; i < N; i++){
    fill(a[i], a[i] + N, INF);
    string str; cin >> str;
    for(int j = 0; j < N; j++){
      if(str[j] == 'Y'){
        a[i][j] = 1;
      }
    }
  }

  for(int k = 0; k < N; k++){
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        if(a[i][k] != INF and a[k][j] != INF){
          a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
        }
      }
    }
  }

  for(int i = 0; i < N; i++){
    int tmp_ans = 0;
    for(int j = 0; j < N; j++){
      if(a[i][j] <= 2 and i != j) tmp_ans++;
    }
    ans = max(tmp_ans, ans);
  }
  cout << ans << "\n";
  return 0;
}