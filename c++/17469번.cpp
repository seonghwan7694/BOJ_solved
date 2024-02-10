#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

struct union_find{
    vector<int> p, s;
    set<int> color[101010];
    union_find(int n) : p(n+1), s(n+1){
        iota(p.begin(), p.end(), 0);
        fill(s.begin(), s.end(), 1);
    }
    int find(int v){
        if(p[v] == v) return v;
        return p[v] = find(p[v]);
    }
    bool merge(int u, int  v){
        u = find(u); v = find(v);
        if(u == v) return false;
        if(s[u] > s[v]){ // s[v] is big
            swap(u, v);
        }
        p[u] = v; s[v] += s[u];
        color[v].insert(color[u].begin(), color[u].end());
        return true;
    }
};

int N, Q;
vector<int> pp;

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> Q;
    struct union_find uf(N+1);
    pp = vector<int>(N+1);
    for(int i = 2; i <= N; i++){
        cin >> pp[i];
    }
    for(int i = 1, c; i <= N; i++){
        cin >> c;
        uf.color[i].insert(c);
    }

    stack<pair<int, int>> query;
    for(int i = 0, X, a; i < N + Q - 1; i++){
        cin >> X >> a;
        query.push({X, a});
    }

    stack<int> ans;
    while(!query.empty()){
        auto &q = query.top();
        if(q.first & 1){
            uf.merge(q.second, pp[q.second]);
        }else{
            ans.push(uf.color[uf.find(q.second)].size());
        }
        query.pop();
    }
    while(!ans.empty()){
        cout << ans.top() << "\n";
        ans.pop();
    }
    return 0;
}