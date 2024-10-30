#include <bits/stdc++.h>
#define MAX_N 101010
using namespace std;

int N, M, p[MAX_N], ans;

int Find(int u){
    if(p[u] != u) return p[u] = Find(p[u]);
    return u;
}

void Merge(int u, int v){
    int pu = Find(u);
    int pv = Find(v);
    if(pu < pv) p[pv] = pu;
    else p[pu] = pv;
    return;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    int u, v;
    for(int i = 0; i < MAX_N; i++) p[i] = i;
    while(M--){
        cin >> u >> v;
        Merge(u, v);
    }
    
    int from, to;
    N--, cin >> from;
    while(N--){
        cin >> to;
        if(Find(from) != Find(to)){
            ans++;
            from = to;
        }
    }
    cout << ans << "\n";
    return 0;
}