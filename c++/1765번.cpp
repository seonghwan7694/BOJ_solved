#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int n, m;
int parent[2020], Enemy[2020];

void init(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }
}

int Find(int u){
    if(parent[u] == u) return u;
    return parent[u] = Find(parent[u]);
}

void Merge(int u, int v){
    int uu = Find(u);
    int vv = Find(v);
    if(uu > vv){
        parent[uu] = vv;
    }else{
        parent[vv] = uu;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m;   
    init();
    for(int i = 0, p, q; i < m; i++){
        char c;
        cin >> c >> p >> q;
        if(c == 'F'){
            Merge(p, q);
        }else{
            if(Enemy[p] == 0) Enemy[p] = q;
            else Merge(Enemy[p], q);
            if(Enemy[q] == 0) Enemy[q] = p;
            else Merge(Enemy[q], p);
        }
    }


    set<int> s;
    for(int i = 1; i <= n; i++){
        s.insert(Find(i));
    }
    cout << s.size() << "\n";
    return 0;
}