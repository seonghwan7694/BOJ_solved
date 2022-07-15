#include <bits/stdc++.h>
using namespace std;

int N, K, query, u, v;
int a[404][404];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> K;
  while(K--){
    cin >> u >> v; // u : 먼저 일어난 사건, v : 나중에 일어난 사건
    a[u][v] = -1; // 앞에 있는 번호(u)의 사건이 먼저 일어났으므로, -1 이다.
    a[v][u] = 1; // 뒤에 있는 번호(u)의 사건이 먼저 일어났으므로, 1 이다.
  }

  for(int k = 1; k <= N; k++){
    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= N; j++){
        if(a[i][k] == -1 and a[k][j] == -1){ // (i가 일어난 시간) < (k가 일어난 시간) < (j가 일어난 시간)
          a[i][j] = -1;
          a[j][i] = 1;
        }
      }
    }
  }

  cin >> query;
  while(query--){
    cin >> u >> v;
    cout << a[u][v] << "\n";   
  }
  return 0;
}