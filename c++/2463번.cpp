#include <bits/stdc++.h>
using namespace std;
#define lld long long int
#define DEBUG 0
const lld MOD = 1e9;
constexpr lld SZ = 101010;

lld parent[SZ], siz[SZ], rk[SZ];
typedef struct{
    lld u, v, c;
} edge;
lld res;
vector<edge> E;



void init(){
    for (int i=0; i<SZ; i++) {
        parent[i] = i;
        siz[i] = 1;
        rk[i] = 0;
    }
}

int fnd(int p){
    if(parent[p] == p) return p;
    return parent[p] = fnd(parent[p]);
}

void uni(int p, int q){
    p = fnd(p);
    q = fnd(q);
    if(rk[p] < rk[q]) parent[p] = q, siz[q] += siz[p];
    else parent[q] = p, siz[p] += siz[q];;
    if(rk[p] == rk[q]) rk[p]++;
}
lld sum_c;

int N, M;

void solve(){
    for(auto &x : E){
        int p_u = fnd(x.u);
        int p_v = fnd(x.v);
        if(p_u == p_v){
            sum_c -= x.c;
            continue;
        }
        // cout << siz[p_u] << " "; cout << siz[p_v] << " "; cout << sum_c << "\n";
        res += (siz[p_u] * siz[p_v] * sum_c);
        sum_c -= x.c;
        res %= MOD;
        uni(x.u, x.v);
    }
    cout << res << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> M;
    init();
    edge e;
    for(lld i = 0; i < M; i++){
        cin >> e.u >> e.v >> e.c;
        if(e.u > e.v) swap(e.u, e.v);
        E.push_back({e.u, e.v, e.c});
        sum_c += e.c;
    }

    sort(E.begin(), E.end(), [](edge &e1, edge &e2){
        return e1.c > e2.c;
    });

    if(DEBUG){
        cout << "\n"; for(auto &x : E){ cout << x.u << " "; cout << x.v << " "; cout << x.c << " "; cout << "\n"; }
    }
    if(!DEBUG) solve();
    return 0;
}