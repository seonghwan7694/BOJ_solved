#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int N, M;
int a[101][101];

void floyd(){
  for(int k = 1; k <= N; k++){
    for(int i = 1; i <= N; i++){
      for(int j = 1; j <= N; j++){
        if(a[i][k] == a[k][j] and a[i][k] != 0){
          a[i][j] = a[i][k];
        }
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> N >> M;
  while(M--){
    int u, v;
    cin >> u >> v; // u -> v;
    a[u][v] = 1;
    a[v][u] = -1;
  }
  floyd();

  for(int i = 1; i <= N; i++){
    int cnt = N - 1;
    for(int j = 1; j <= N; j++){
      if(a[i][j] != 0) cnt--;
    }
    cout << cnt << "\n";
  }
  return 0;
}