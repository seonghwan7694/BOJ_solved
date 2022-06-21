#include <bits/stdc++.h>
using namespace std;

int N, st, en;
int MAP[10101];
bool visited[10101];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for(int i = 1; i <= N; i++){
    cin >> MAP[i];
  }
  cin >> st >> en;

  queue<pair<int, int>> q; // cur, cnt
  visited[st] = true; q.push({st, 0});
  
  while(!q.empty()){
    auto cur = q.front(); q.pop();
    if(cur.first == en){
      cout << cur.second << "\n";
      return 0;
    }
    for(int i = 1; i < 10101; i++){
      if(cur.first + MAP[cur.first]*i > N) break;
      if(visited[cur.first + MAP[cur.first]*i]) continue;

      visited[cur.first + MAP[cur.first]*i] = true; q.push({cur.first + MAP[cur.first]*i, cur.second + 1});
    }
    for(int i = -1; i > -10101; i--){
      if(cur.first + MAP[cur.first]*i < 1) break;
      if(visited[cur.first + MAP[cur.first]*i]) continue;

      visited[cur.first + MAP[cur.first]*i] = true; q.push({cur.first + MAP[cur.first]*i, cur.second + 1});
    } 
  }
  cout << -1 << "\n";
  return 0;
}