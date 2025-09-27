#include <bits/stdc++.h>
using namespace std;

int N, M;
double A[51];
vector<int> g[51];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(9);
    cin >> N >> M;
    for(int i = 0, v, w; i < M; i++){
        cin >> v >> w;
        g[v].push_back(w);
    }
    A[1] = 100;
    for(int i = 1; i <= N; i++){
        if(g[i].empty()) continue;
        double water = A[i] / g[i].size();
        for(auto j : g[i]){
            A[j] += water;
        }
        A[i] = 0;
    }
    cout << *max_element(A, A + 51) << "\n";
    return 0;
}