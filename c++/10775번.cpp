#include <bits/stdc++.h>
using namespace std;

struct union_find{
    vector<int> p, l, r;

    union_find(int n) : p(n), l(n), r(n){
        iota(p.begin(), p.end(), 0);
        iota(l.begin(), l.end(), 0);
        iota(r.begin(), r.end(), 0);
    }

    int find(int n){
        return (p[n] == n ? n : p[n] = find(p[n]));
    }

    void merge(int u, int v){
        u = find(u);
        v = find(v);
        if(u == v) return;

        p[v] = u;
        l[u] = min(l[v], l[u]);
        r[u] = max(r[v], r[u]);
    }

    int prev(int x){
        return find(l[find(x)] - 1);
    }
    int next(int x){
        return find(r[find(x)] + 1);
    }
};

struct uf_set{
    struct union_find uf;
    vector<int> chk;
    uf_set(int n) : uf(n + 2), chk(n + 2){ }
    void erase(int x){
        chk[x] = 1;
        if(chk[x-1]) uf.merge(x-1, x);
        if(chk[x+1]) uf.merge(x, x+1);
    }
    int prev(int x){
        do x = uf.prev(x); while(chk[x]);
        return x;
    }
    int next(int x){
        do x = uf.next(x); while(chk[x]);
        return x;
    }
    int front(){return next(0);}
    int back(){return prev(chk.size() - 1);}
};

int G, P;
int main(){
    ios::sync_with_stdio(false);
    cin >> G >> P;
    uf_set ufs(G);
    
    for(int i = 1, t, pos; i <= P; i++){
        cin >> t;
        pos = ufs.prev(t+1);
        if(pos == 0){
            cout << i - 1 << "\n";
            return 0;
        }else{
            ufs.erase(pos);
        }
    }
    cout << P << "\n";
    return 0;
}