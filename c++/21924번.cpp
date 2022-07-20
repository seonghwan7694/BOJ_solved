#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;
#define ll long long
ll MAXCOST;
ll V, E, parent[101010];
vector<tuple<int, int, int>> edges;

ll find(int x){
  if(parent[x] == x) return x;
  return parent[x] = find(parent[x]);
}

bool merge(ll u, ll v){
  u = find(u);
  v = find(v);
  if(u == v) return false;
  if(u < v) parent[u] = v;
  else parent[v] = u;
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> V >> E;
  for(ll i = 1; i <= V; i++){
    parent[i] = i;
  }
  while(E--){
    ll u, v, c;
    cin >> u >> v >> c;
    edges.push_back(make_tuple(c, u, v));
    MAXCOST += c;
  }
  sort(edges.begin(), edges.end());

  ll ans = 0, cnt = 0;
  for(auto x : edges){
    ll c = get<0>(x);
    ll u = get<1>(x);
    ll v = get<2>(x);
    if(merge(u, v)){
      ans += c;
      cnt++;
    }
    if(cnt == V - 1) break;
  }
  if(cnt != V - 1){
    cout << -1 << "\n";
    return 0;
  }
  cout << MAXCOST - ans << "\n";
  return 0;
}