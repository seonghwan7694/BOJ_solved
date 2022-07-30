#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX_SIZE 100000
ll N;
ll S[20];
// 1 to 99999
bool vis[MAX_SIZE * 21];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;
  for(ll i = 0; i < N; i++){
    cin >> S[i];
  }

  ll A = (1LL << N) - 1;
  for(ll subset = A; subset; subset = ((subset - 1) & A)){
    int tmp = 0;
    for(int i = 0; i < N; i++){
      if(subset & (1LL << i)) tmp += S[i];
    }
    vis[tmp] = true;
  }

  for(int i = 1; i <= (MAX_SIZE * 21); i++){ 
    if(!vis[i]){
      cout << i << "\n";
      break;
    }
  }
  return 0;
}