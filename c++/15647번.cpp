#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 303030
#define ll long long
ll N;
vector<pair<ll , ll>> g[MAX_SIZE];
ll tree_size[MAX_SIZE], dist, ans[MAX_SIZE];
bool vis[MAX_SIZE];

ll dfs(ll cur, ll cost){ // 루트에서 cur까지 가는데 드는 비용은 cost이다.
    if(vis[cur]) return 0;

    vis[cur] = true;
    tree_size[cur] = 1;

    for(auto [next, w] : g[cur]){
        if(vis[next]) continue;
        dist += cost + w;
        tree_size[cur] += dfs(next, cost + w);
    }
    return tree_size[cur];
}

void dfs2(int cur, int prev, ll d, ll cost){
    vis[cur] = true;

    ll new_dist = d;
    if(prev != 0){
        new_dist -= cost * (tree_size[cur] - 1);
        new_dist += cost * (N - tree_size[cur] - 1);
    }
    ans[cur] = new_dist;
    for(auto [next, w] : g[cur]){
        if(vis[next]) continue;
        dfs2(next, cur, new_dist, w);
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 1, u, v, d; i < N; i++){
        cin >> u >> v >> d;
        g[u].push_back({v, d});
        g[v].push_back({u, d});
    }
    dfs(1, 0);
    fill(vis, vis + MAX_SIZE, false);
    dfs2(1, 0, dist, 0);
    for(int i = 1; i <= N; i++){ cout << ans[i] << "\n"; }

    return 0;
}