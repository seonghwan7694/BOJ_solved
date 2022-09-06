#include <bits/stdc++.h>
using namespace std;

int t, n;
vector<pair<int, int>> store;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int x_home, y_home;
int x_des, y_des;
bool vis[101];
string BFS(){
  queue<pair<int, int>> q;
  q.push({x_home, y_home});

  while(!q.empty()){
    auto cur = q.front();
    q.pop();

    if(abs(cur.first - x_des) + abs(cur.second - y_des) <= 1000) return "happy";

    for(int i = 0; i < store.size(); i++){
      if(abs(cur.first - store[i].first) + abs(cur.second - store[i].second) <= 1000){
        if(!vis[i]){
          vis[i] = true;
          q.push({store[i].first, store[i].second});
        }
      }
    }
  }
  return "sad";
}
void solution(){
  cin >> n;
  cin >> x_home >> y_home;
  for(int i = 0, x, y; i < n; i++){
    cin >> x >> y;
    store.push_back({x, y});
  }
  cin >> x_des >> y_des;
  cout << BFS() << "\n";
  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> t;
  while(t--){
    store.clear();
    fill(vis, vis + 101, false);
    solution();
  }

  return 0;
}