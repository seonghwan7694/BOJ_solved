#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 505050
int N, M, parent[MAX_SIZE], ans = MAX_SIZE;
vector<pair<int, int>> g;

int Find(int u){
    if(u == parent[u]) return u;
    return parent[u] = Find(parent[u]);
}

bool Union(int u, int v){
    u = Find(u);
    v = Find(v);
    if(u == v) return false;
    parent[u] = v;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++) parent[i] = i;
    for(int i = 0, u, v; i < M; i++){
        cin >> u >> v;
        g.push_back({u, v});
    }   
    for(int i = 0; i < M; i++){
        auto [u, v] = g[i];
        if(Union(u, v) == false){
            cout << i + 1 << "\n";
            return 0;
        }
    }
    cout << 0 << "\n";
    return 0;
}