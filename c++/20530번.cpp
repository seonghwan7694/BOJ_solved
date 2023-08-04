#include <bits/stdc++.h>
using namespace std;

int N, Q;
vector<int> graph[202020];
bool cycle_node[202020];
bool vis[202020];

int dfs(int prev_u, int u){
    int cn;
    for(auto next_u : graph[u]){
        if(prev_u != next_u and !vis[next_u]){
            vis[next_u] = true;
            cn = dfs(u, next_u);
        }else{
            cycle_node[next_u] = true;
            return cn;
        }
    }
    return cn;
}

int cycle_dfs(int prev_u, int u){
    memset(vis, false, sizeof vis);
    for(auto next_u : graph[u]){
        if(prev_u != next_u and !vis[next_u]){
            dfs(u, next_u);
        }else{
            
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin >> N >> Q;
    for(int i = 1, a, b; i <= N; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    while(Q--){
        int u, v;
        cin >> u >> v;
    }


    return 0;
}