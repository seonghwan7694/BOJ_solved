#include <bits/stdc++.h>
using namespace std;
vector<tuple<int, int, int, int>> line;
int N, ANS;
int p[3030], Size[3030];

int Find(int u){
    if(p[u] == u) return u;
    return p[u] = Find(p[u]);
}

void Union(int u, int v){
    u = Find(u);
    v = Find(v);
    if(u == v) return;
    p[v] = u;
    Size[u] += Size[v];
    ANS--;
}

bool CCW(pair<int, int> &a, pair<int, int> &b, pair<int, int> &c){
    return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first) > 0;
}

bool func(int u, int v){
    auto [ux1, uy1, ux2, uy2] = line[u];
    auto [vx1, vy1, vx2, vy2] = line[v];
    pair<int, int> A = {ux1, uy1};
    pair<int, int> B = {ux2, uy2};
    pair<int, int> C = {vx1, vy1};
    pair<int, int> D = {vx2, vy2};
    if(CCW(A, B, C) * CCW(A, B, D) > 0) return false;
    if(CCW(C, D, A) * CCW(C, D, B) > 0) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    ANS = N;
    for(int i = 0, x1, y1, x2, y2; i < N; i++){
        cin >> x1 >> y1;
        cin >> x2 >> y2;
        line.push_back({x1, y1, x2, y2});
        p[i] = i;
        Size[i] = 1;
    }
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if(func(i, j)){
                Union(i, j);
            }
        }
    }
    cout << ANS << "\n";
    cout << *max_element(Size, Size + N) << "\n";
    return 0;
}