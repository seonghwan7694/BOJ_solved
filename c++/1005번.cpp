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

int TC, N, K, D[1010], X, Y, W, in_degree[1010];
int dp[1010]; // dp[i] = val : i 지점을 방문하는데 걸리는 시간은 val 입니다.
vector<int> adj[1010];

void topologySort(){
  queue<pair<int, int>> q; // {현재 노드, 현재 시간}
  for(int i = 1; i <= N; i++){
    if(in_degree[i] == 0){
      dp[i] = D[i]; // i 지점을 방문하는데 걸리는 시간은 D[i] 입니다.
      q.push({i, dp[i]});
    }
  }
  while(!q.empty()){
    auto cur = q.front(); q.pop();
    if(cur.first == W){
      cout << cur.second << "\n";
      return;
    }
    for(auto nxt : adj[cur.first]){
      if(--in_degree[nxt] == 0){
        dp[nxt] = max(dp[nxt], cur.second + D[nxt]); // nxt 지점을 가는데 걸리는 시간 중 최대 시간을 저장합니다.
        q.push({nxt, dp[nxt]}); // nxt 지점을 방문하는데 걸리는 시간은 cur.second + dp[nxt] 입니다.
      }else{
        dp[nxt] = max(dp[nxt], cur.second + D[nxt]); // nxt 지점을 가는데 걸리는 시간 중 최대 시간을 저장합니다.
      }
    }
  }
  return;
}

void solution(){
  cin >> N >> K;
  fill(D, D + 1010, 0);
  fill(dp, dp + 1010, 0);
  fill(in_degree, in_degree + 1010, 0);
  for(int i = 1; i <= N; i++){
    adj[i].clear();
  }
  for(int i = 1; i <= N; i++){
    cin >> D[i];
  }
  while(K--){
    cin >> X >> Y; // X 건물을 지은 후, Y 건물을 짓는다.
    adj[X].push_back(Y);
    in_degree[Y]++;
  }
  cin >> W; // 승리하기 위해 지어야할 건물의 번호

  topologySort();
  return;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> TC;
  while(TC--){
    solution();
  }



  return 0;
}