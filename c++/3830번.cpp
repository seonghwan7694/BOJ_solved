#include <bits/stdc++.h>
#include <iterator>
#define INF INT32_MAX
using namespace std;


vector<int> p(101010, 0), s(101010, 1), w(101010, 0);

void init(int N){
    for(int i = 1; i <= N; i++){
        p[i] = i;
        w[i] = 0;
    }
}

int find(int u){
    if(u == p[u]) return u;
    int pu = find(p[u]);
    w[u] += w[p[u]];
    return p[u] = pu;
}

void merge(int u, int v, int _w){
    int pu = find(u);
    int pv = find(v);
    if(pu == pv) return;
    p[pv] = pu;
    w[pv] = - w[v] + w[u] - _w;
}

void query(int a, int b){
    int pa = find(a);
    int pb = find(b);
    if(pa == pb){
        cout << w[a] - w[b] << "\n";
    }else{
        cout << "UNKNOWN" << "\n";
    }
}

void solve(int N, int Q){
    init(N);
    char cmd;
    int a, b, w;
    while(Q--){
        cin >> cmd;
        if(cmd == '!'){
            cin >> a >> b >> w;
            merge(a, b, w);
        }else{
            cin >> a >> b;
            query(a, b);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N, Q;
    while(true){
        cin >> N >> Q;
        if(N == 0 and Q == 0) break;
        solve(N, Q);
    }
    return 0;
}