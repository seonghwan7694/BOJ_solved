#include <bits/stdc++.h>
using namespace std;
#define lld long long int
lld N, a, b;
vector<pair<lld , lld>> graph[101010];
bool vis[101010];
bool flag;

void dfs(lld u, lld sum, lld max_weight){
    if(flag) return;
    if(u == b){
        cout << sum - max_weight << "\n";
        flag = true;
        return;
    }

    for(auto [v, w] : graph[u]){
        if(!vis[v]){
            vis[v] = true;
            dfs(v, sum + w, max(w, max_weight));
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin >> N >> a >> b;
    for(lld i = 0, u, v, w; i < N - 1; i++){
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    vis[a] = true;
    dfs(a, 0, 0);
    return 0;
}