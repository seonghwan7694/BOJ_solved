#include <bits/stdc++.h>
using namespace std;

int N, Q;

struct union_find{
    vector<int> p;
    vector<set<int>> S;
    union_find(int n): p(n+1), S(n+1){
        iota(p.begin(), p.end(), 0);
    }

    int find(int x){
        return x == p[x] ? x : p[x] = find(p[x]);
    }

    void merge(int u, int v){ // merge set(u), set(v)
        if(S[u].size() < S[v].size()) swap(S[u], S[v]); // small to large
        for(auto &x : S[v]) S[u].insert(x);
        S[v].clear();
        p[v] = u;
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> Q;   
    union_find uf(N);
    for(int i = 1, n; i <= N; i++){
        cin >> n;
        for(int j = 0, tmp; j < n; j++){
            cin >> tmp;
            uf.S[i].insert(tmp);
        }
    }

    int c, a, b;
    while(Q--){
        cin >> c;
        if(c & 1){
            cin >> a >> b;
            uf.merge(a, b); // merge set(a), set(b)
        }else{
            cin >> a;
            cout << uf.S[a].size() << "\n";
        }
    }
    return 0;
}