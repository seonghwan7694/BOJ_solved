#include <bits/stdc++.h>
using namespace std;

int N, M, Q;
vector<int> parent, a, b;

int Find(int u){
    if(u == parent[u]) return u;
    return parent[u] = Find(parent[u]);
}

void Merge(int u, int v){
    u = Find(u);
    v = Find(v);
    if(u == v) return;

    if(a[u] + b[u] < a[v] + b[v]) {
        parent[u] = v;
        a[v] += a[u];
        b[v] += b[u];
    } else {
        parent[v] = u;
        a[u] += a[v];
        b[u] += b[v];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> M >>  Q;
    parent.resize(N + 1);
    a.resize(N + 1);
    b.resize(N + 1);

    for(int i = 1, tmp; i <= N; i++){
        cin >> tmp;
        if(tmp) a[i]++;
        else b[i]++;
        parent[i] = i;
    }
    for(int i = 0, u, v; i < M; i++){
        cin >> u >> v;
        Merge(u, v);
    }
    for(int i = 0, p, k; i < Q; i++){
        cin >> k;
        p = Find(k);
        if(a[p] > b[p]) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
    return 0;
}
