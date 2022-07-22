#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll N, M, parent[1010];
vector<tuple<ll, ll, ll>> edges;
double ans;

struct compare{
  bool operator()(pair<ll, pair<ll, ll>> u, pair<ll, pair<ll, ll>> v){
    return u.first > v.first;
  }
};

ll Find(ll u){
  if(parent[u] == u) return u;
  return parent[u] = Find(parent[u]);
}

bool Merge(ll u, ll v){
  u = Find(u);
  v = Find(v);
  if(u == v) return false;
  if(u > v) parent[u] = v;
  else parent[v] = u;
  return true;
}

pair<ll, pair<ll, ll>> get_distance(tuple<ll, ll, ll>& u, tuple<ll, ll, ll>& v){
  ll u_idx, u_x, u_y, v_idx, v_x, v_y;
  tie(u_idx, u_x, u_y) = u;
  tie(v_idx, v_x, v_y) = v;
  return {(u_x - v_x)*(u_x - v_x) + (u_y - v_y)*(u_y - v_y), {u_idx, v_idx}};
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cout << fixed;
  cout.precision(2);

  cin >> N >> M;

  for(ll i = 1, u, v; i <= N; i++){
    cin >> u >> v;
    edges.push_back({i, u, v});
    parent[i] = i;
  }

  for(ll i = 1, u, v; i <= M; i++){
    cin >> u >> v;
    Merge(u, v);
  }
  
  priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, compare> pq;
  for(ll i = 0; i < edges.size() - 1; i++){
    for(ll j = i + 1; j < edges.size(); j++){
      pq.push(get_distance(edges[i], edges[j]));
    }
  }
  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    if(Merge(cur.second.first, cur.second.second)){
      ans += sqrt((double) cur.first);
    }
  }
  cout << ans << "\n";
  return 0;
}