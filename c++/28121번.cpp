#include <bits/stdc++.h>
using namespace std;

int N, Q;

struct union_find{
    int res, n; vector<int> p, s;

    union_find(int n) : p(n+n), s(n+n), res(0), n(n){
        iota(p.begin(), p.end(), 0);
        fill(s.begin(), s.begin() + n, 1);
    }
    int neg(int v){ return (v < n ? v + n : v - n); }
    int Find(int u){
        if(p[u] == u) return u;
        return p[u] = Find(p[u]);
    }
    void Merge(int u, int v){
        u = Find(u);
        v = Find(v);
        if(u == v) return;
        if(Find(neg(u)) == u) res -= s[u];
        if(Find(neg(v)) == v) res -= s[v];
        s[v] += s[u]; p[u] = v;
        if(Find(neg(v)) == v) res += s[v];
    }
    void add_edge(int u, int v){
        Merge(u, neg(v));
        Merge(v, neg(u));
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> N >> Q;
    struct union_find uf(N);
    for(int i = 0,a ,b ; i < Q; i++){
        cin >> a >> b;
        uf.add_edge(a, b);
        cout << uf.res << "\n";
    }


    return 0;
}