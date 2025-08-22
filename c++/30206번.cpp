#include <iostream>
#include <vector>
#include <queue>
#define ll long long
using namespace std;
#define MOD 1'000'000'000 + 7

ll N, M, L[200'001], ret = 1, lev = 0;
bool vis[200'001];
vector<ll> g[200'001];
priority_queue<pair<ll, ll>> q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for(ll e = 0, u, v; e < M; e++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    q.push({1, 1});
    vis[1] = true;
    while(!q.empty()){
        auto [u, l] = q.top();
        q.pop();
        L[l]++;
        for(auto v : g[u]){
            if(!vis[v]){
                q.push({v, l + 1});
                vis[v] = true;
            }
        }
    }
    for(ll i = 1;i < 200'001; i++){
        if(L[i] == 0) break;
        ret *= L[i] + 1;
        ret %= MOD;
    }
    cout << ret - 1 << "\n";
    return 0;
}