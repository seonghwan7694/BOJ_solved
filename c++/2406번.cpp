#include <bits/stdc++.h>
using namespace std;


/*

네트워크에 고장이 발생하더라도 컴퓨터들이 연결되어 있도록 안정적인 네트워크를 구축
네트워크에 고장이 발생하는 경우는 두 가지가 있다.

첫 번째는 직접 연결되어 있는 두 컴퓨터의 연결이 끊어지는 경우이다.
-> 회사 측은 이런 경우에도 이 두 컴퓨터가 다른 컴퓨터들을 경유하여 연결되어 있기를 원한다.
두 번째는 컴퓨터가 고장 나는 경우이다.
-> 회사 측은 이런 경우에는 고장 나지 않은 컴퓨터들끼리 연결되어 있기를 원한다.

*/

/*
const int INF = 987654321;
int n, m, x, y, cost[1010][1010], X = INF, parent[1010];
vector<pair<int, int>> edges; // {u, v}
vector<tuple<int, int, int>> EDGES; // {cost, u, v}
vector<pair<int, int>> ans; // {u, v}

vector<pair<int, int>> tmp_ans;
int tmp_X;

int Find(int u){
  if(u == parent[u]) return u;
  return parent[u] = Find(parent[u]);
}

bool Merge(int u, int v){
  u = Find(u);
  v = Find(v);
  if(u == v) return false;
  if(u > v) parent[u] = v;
  else parent[v] = u;
  return true;
}

void MST_1(pair<int, int> e_broken){
  // 간선 e 는 고장 -> 나머지 연결된 상태를 유지해야함.

  for(int i = 1; i <= n; i++){
    parent[i] = i;
  }
  
  for(auto e : edges){
    if(e_broken.first == e.first and e_broken.second == e.second) continue;
    Merge(e.first, e.second);
  }

  for(auto &E : EDGES){
    if(Merge(get<1>(E), get<2>(E))){
      tmp_ans.push_back({get<1>(E), get<2>(E)});
      tmp_X += cost[get<1>(E)][get<2>(E)];
    }
  }
  return;
}
void MST_2(int u){ 
  // u는 고장난 컴퓨터 -> u를 제외한 나머지 컴퓨터는 MST일 필요는 없지만 일단 ^^

  for(int i = 1; i <= n; i++){
    parent[i] = i;
  }
  for(auto e : edges){
    if(u == e.first or u == e.second) continue;
    Merge(e.first, e.second);
  }

  for(auto &E : EDGES){
    if(u == get<1>(E) or u == get<2>(E)) continue;
    if(Merge(get<1>(E), get<2>(E))){
      tmp_ans.push_back({get<1>(E), get<2>(E)});
      tmp_X += cost[get<1>(E)][get<2>(E)];
    }
  }
  return;
}

void input(){
  cin >> n >> m;
  for(int i = 2; i <= n; i++){
    edges.push_back({1, i});
  }
  while(m--){
    cin >> x >> y;
    if(x > y) swap(x, y); // x < y 인 상태를 유지(쓸모는 없겠지만)
    edges.push_back({x, y});
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      cin >> cost[i][j];
    }
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      EDGES.push_back({cost[i][j], i, j});
    }
  }
  sort(EDGES.begin(), EDGES.end());
  return;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  
  // 첫번째 경우 : 컴퓨터1 과 컴퓨터2가 연결된 간선이 고장나는 경우
  for(auto e : edges){
    tmp_X = 0;
    tmp_ans.clear();
    MST_1(e);

    if(tmp_X == 0) continue; // 간선 e 가 사라져도, 연결된 상태를 유지함.
    if(X > tmp_X){
      X = tmp_X;
      ans = tmp_ans;
    }
  }

  // 두번째 경우 : 컴퓨터가 고장나는 경우
  for(int i = 1; i <= n; i++){
    tmp_X = 0;
    tmp_ans.clear();
    MST_2(i);

    if(tmp_X == 0) continue; // i번 컴퓨터가 고장이여도, 연결된 상태를 유지함.
    if(X > tmp_X){
      X = tmp_X;
      ans = tmp_ans;
    }
  }



  if(X == INF){
    cout << 0 << " " << 0 << "\n";
  }else{
    cout << X << " " << ans.size() << "\n";
    for(auto cur : ans){
      cout << cur.first << " " << cur.second << "\n";
    }
  }
  return 0;
}
*/

int n, m, x, y, cost[1010][1010], X, parent[1010];
vector<pair<int, int>> edges; // {u, v}
vector<tuple<int, int, int>> EDGES; // {cost, u, v}
vector<pair<int, int>> ans;

int Find(int u){
  if(u == parent[u]) return u;
  return parent[u] = Find(parent[u]);
}

bool Merge(int u, int v){
  u = Find(u);
  v = Find(v);
  if(u == v) return false;
  if(u > v) parent[u] = v;
  else parent[v] = u;
  return true;
}

void input(){
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    parent[i] = i;
  }
  while(m--){
    cin >> x >> y;
    if(x > y) swap(x, y); // x < y 인 상태를 유지(쓸모는 없겠지만)
    Merge(x, y);
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      cin >> cost[i][j];
    }
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      EDGES.push_back({cost[i][j], i, j});
    }
  }
  sort(EDGES.begin(), EDGES.end());
  return;
}

void solution(){

  for(auto E : EDGES){
    if(get<1>(E) == 1 or get<2>(E) == 1) continue;
    if(Merge(get<1>(E), get<2>(E))){
      X += get<0>(E);
      ans.push_back({get<1>(E), get<2>(E)});
    }
  }

  cout << X << " " << ans.size() << "\n";
  for(auto x : ans){
    cout << x.first << " " << x.second << "\n";
  }

  return;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solution();


}