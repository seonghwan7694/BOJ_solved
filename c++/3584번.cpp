#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int test_case; cin >> test_case;
  while(test_case--){
    int N; cin >> N;
    vector<int> graph[10101]; for(int i = 0; i < 10101; i++) graph[i].clear();
    bool visited[10101]; fill(visited, visited + 10101, false);

    for(int i = 0; i < N - 1; i++){
      int u, v; cin >> u >> v; // u가 v의 부모
      graph[v].push_back(u); // v -> u
    }
    int A, B; cin >> A >> B;
    queue<int> q;
    q.push(A); visited[A] = true;
    while(!q.empty()){
      int cur = q.front(); q.pop();
      for(auto x : graph[cur]){
        if(!visited[x]){
          visited[x] = true;
          q.push(x);
        }
      }
    }
    q.push(B);
    if(visited[B]){
      cout << B << "\n";
      continue;
    }
    while(!q.empty()){
      int cur = q.front(); q.pop();
      for(auto x : graph[cur]){
        if(visited[x]){
          cout << x << "\n";
          while(!q.empty()) q.pop();
        }else{
          q.push(x);
        }
      }
    }
  }
  return 0;
}