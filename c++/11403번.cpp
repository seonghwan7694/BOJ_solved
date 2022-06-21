#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> graph[101];
int ans[101][101];
bool visited[101];

void dfs(int cur){
  for(auto x : graph[cur]){
    if(visited[x]) continue;
    visited[x] = true;
    dfs(x);
  }
}



int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;

  // 정점의 개수 : N
  // 간선의 개수의 최대 : N 제곱

  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= N; j++){
      int tmp; cin >> tmp;
      if(tmp == 1) graph[i].push_back(j); // i에서 j로 가는 간선이 존재함
    }
  }

  for(int i = 1; i <= N; i++){
    fill(visited, visited + 101, false);
    dfs(i);
    for(int j = 1; j <= N; j++){
      cout << visited[j] << " ";
    }
    cout << "\n";
  }
  return 0;
}