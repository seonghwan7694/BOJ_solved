#include <vector>
#include <iostream>
#include <queue>
using namespace std;
#define INF 987654321
int V, E, S, D;
vector<int> ans;
vector<pair<int, int>> g[500], rg[500];
vector<int> d;
bool erased_edge[500][500], vis[500];
void dijkstra(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    d = vector<int>(V, INF);
    pq.push({0, S});
    d[S] = 0;
    while(!pq.empty()){
        auto [cost, u] = pq.top();
        pq.pop();
        if(d[u] < cost) continue;
        for(auto [v, w] : g[u]){
            if(erased_edge[u][v]) continue;
            if(d[v] > cost + w){
                d[v] = cost + w;
                pq.push({cost + w, v});
            }
        }
    }
}

void dfs(int v){
    if(vis[v]) return;
    vis[v] = true;
    for(auto [prev_v, prev_cost] : rg[v]){
        if(d[v] != INF && d[prev_v] + prev_cost == d[v]){
            erased_edge[prev_v][v] = true;
            dfs(prev_v);
        }
    }
   
}
void solution(){
    cin >> S >> D;
    for(int i = 0; i < 500; i++){
        g[i].clear();
        fill(erased_edge[i], erased_edge[i] + 500, 0);
        rg[i].clear();
    }
    for(int e = 0, u, v, w; e < E; e++){
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        rg[v].push_back({u, w});
    }
    dijkstra();
    if(d[D] != INF){
        fill(vis, vis + 500, false);
        dfs(D);
        dijkstra();
    }
    ans.push_back(d[D] == INF ? -1 : d[D]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(true){
        cin >> V >> E;
        if(V == 0 and E == 0) break;
        solution();
    }
    for(auto x : ans){
        cout << x << "\n";
    }
    return 0;
}