#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <tuple>
#define ll long long
using namespace std;

ll V, E, K;
vector<pair<ll, ll>> graph[1001];
priority_queue<ll> dp[1001]; // dp[v] : 정점 v까지 가는 경로 중 K개 저장

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> V >> E >> K;

    for(ll i = 0, u, v, w; i < E; i++){
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    priority_queue<tuple<ll, ll>> pq; // {cost, v}
    pq.push({0, 1});
    dp[1].push(0);
    while(!pq.empty()){
        auto [cost, u] = pq.top();
        pq.pop();
        cost = -cost;

        for(auto [v, w] : graph[u]){
            ll new_cost = cost + w;
            if(dp[v].size() < K){
                dp[v].push(new_cost);
                pq.push({-new_cost, v});
            }else if(dp[v].top() > new_cost){
                dp[v].pop();
                dp[v].push(new_cost);
                pq.push({-new_cost, v});
            }
        }
   }

    for(int v = 1; v <= V; v++) cout << (dp[v].size() < K ? -1 : dp[v].top()) << "\n";
    return 0;
}