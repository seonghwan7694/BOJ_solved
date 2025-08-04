#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <climits>
using namespace std;
#define ll long long 

ll N, M, K;
ll dp[21][10'001];
vector<pair<ll, ll>> adj[10'001];

int main(){
    cin >> N >> M >> K;
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 0; i <= 20; i++) fill(dp[i], dp[i] + 10'001, LLONG_MAX);
    for(int i = 0, u, v, w; i < M; i++){
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue<tuple<ll, ll, ll>> pq;
    dp[0][1] = 0;
    pq.push({0, 0, 1});

    while(!pq.empty()){
        auto [cost, k, u] = pq.top();
        cost = -cost;
        pq.pop();

        if(dp[k][u] < cost) continue;

        for(auto [v, w] : adj[u]){
            if(dp[k][v] > dp[k][u] + w){
                dp[k][v] = dp[k][u] + w;
                pq.push({-dp[k][v], k, v});
            }

            if(k + 1 <= K and dp[k + 1][v] > dp[k][u]){
                dp[k + 1][v] = dp[k][u];
                pq.push({-dp[k + 1][v], k + 1, v});
            }
        }
    }
    ll ret = dp[0][N];
    for(int k = 1; k <= K; k++){
        ret = min(ret, dp[k][N]);
    }
    cout << ret << "\n";
}

