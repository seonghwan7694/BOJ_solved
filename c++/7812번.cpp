#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 10101
#define ll long long 
bool vis[MAX_SIZE];
ll N, tree_size[MAX_SIZE], dist, min_dist;
vector<pair<ll, ll>> g[MAX_SIZE];
int dfs(int cur, int cost){
    if(vis[cur]) return 0;
    vis[cur] = true;
    tree_size[cur] = 1;
    for(auto [nxt, w] : g[cur]){
        if(vis[nxt]) continue;
        dist += cost + w;
        tree_size[cur] += dfs(nxt, cost + w);
    }
    return tree_size[cur];
}

void dfs2(int cur, int prev, ll d, ll cost){
    if(vis[cur]) return;
    ll new_dist = d;
    vis[cur] = true;
    if(prev != 0){
        new_dist -= cost * (tree_size[cur] - 1);
        new_dist += cost * (N - tree_size[cur] - 1);
    }
    min_dist = min(min_dist, new_dist);
    for(auto [nxt, w] : g[cur]){
        if(vis[nxt]) continue;
        dfs2(nxt, cur, new_dist, w);
    }
    return;
}
void solve(){
    fill(vis, vis + MAX_SIZE, false);
    fill(tree_size, tree_size + MAX_SIZE, 0);
    dist = 0;

    for(int i = 1, u, v, w; i < N; i++){
        cin >> u >> v >> w;
        u++, v++;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    dfs(1, 0);
    fill(vis, vis + MAX_SIZE, false);
    min_dist = dist;
    dfs2(1, 0, dist, 0);
    cout << min_dist << "\n";
    for(int i = 1; i <= N; i++) g[i].clear();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(true){
        cin >> N;
        if(N == 0) break;
        solve();
    }
    return 0;
}