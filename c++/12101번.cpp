#include <bits/stdc++.h>
using namespace std;

int n, k, k_tmp;
int num[20];

void DFS(int cnt, int res){
  if(res == n){
    k_tmp++;
    if(k_tmp == k){
      for(int i = 0; i < cnt; i++){
        cout << num[i];
        if(i != cnt - 1) cout << "+";
      }
      exit(0);
    }
  }else if(res >= n) return;

  // one
  num[cnt] = 1;
  DFS(cnt + 1, res + 1);

  // two
  num[cnt] = 2;
  DFS(cnt + 1, res + 2);

  // three
  num[cnt] = 3;
  DFS(cnt + 1, res + 3);

  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;

  DFS(0, 0);
  cout << -1;
  return 0;
}