#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 100'001

int N, M, from, to, parent[MAX_SIZE];
vector<tuple<int, int, int>> g;

int Find(int u){
    if(u == parent[u]) return u;
    return parent[u] = Find(parent[u]);
}

bool Union(int u, int v){
    u = Find(u);
    v = Find(v);
    if(u == v){
        return false;
    }
    parent[u] = v;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0, A, B, C; i < M; i++){
        cin >> A >> B >> C;
        g.push_back({C, A, B});
    }
    for(int i = 1; i <= N; i++) parent[i] = i;
    cin >> from >> to;
    sort(g.begin(), g.end(), [](auto &a, auto &b){
        return get<0>(a) > get<0>(b);
    });
    for(auto [w, u, v] : g){
        Union(u, v);
        if(Find(from) == Find(to)){
            cout << w << "\n";
            exit(0);
        }
    }
    return 0;
}