#include <bits/stdc++.h>
using namespace std;

int N;
bool cycle[3030];
vector<int> adj[3030];
bool visited[3030];
int pre[3030];
bool hasCycle;
int dist[3030];

void bfs(){
  queue<pair<int, int>> q;
  for(int i = 1; i <= N; i++){
    if(cycle[i]){
      visited[i] = true;
      q.push({i, 0});
    }
  }
  while(!q.empty()){
    int cur = q.front().first;
    int dis = q.front().second;
    q.pop();
    visited[cur] = true;

    for(auto& next : adj[cur]){
      if(visited[next]) continue;
      dist[next] = dis + 1;
      q.push({next, dis + 1});
    }
  }
}
void findCycle(int cur){
  visited[cur] = true;

  for(int i = 0; i < adj[cur].size(); i++){
    if(hasCycle) return;
    int next = adj[cur][i];
    if(visited[next]){
      if(next != pre[cur]){
        cycle[cur] = true;
        hasCycle = true;
        while(cur != next){
          cycle[pre[cur]] = true;
          cur = pre[cur];
        }
        return;
      }
    }else{
      pre[next] = cur;
      findCycle(next);
    }
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  for(int i = 0, u, v; i < N; i++){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  findCycle(1);
  memset(visited, false, sizeof visited);
  bfs();
  for(int i = 1; i <= N; i++){
    cout << dist[i] << " ";
  }


  




  return 0;
}