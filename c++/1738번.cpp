#include <bits/stdc++.h>
using namespace std;
#define INF 20'000 * 1'0000ll
#define ll long long
int V, E;
vector<tuple<int, int, ll>> g;
long long D[101], B[101];
vector<int> cy, ans;
bool cycle;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> V >> E;
    fill(D, D + 101, INF);
    fill(B, B + 101, INF);
    for(int i = 0, u, v, w; i < E; i++){
        cin >> u >> v >> w;
        g.push_back({u, v, -w});
    }

    D[1] = 0;
    B[1] = 0;
    for(int iter = 1; iter <= V; iter++){
        bool isChanged = false;
        for(const auto &[s, e, w] : g){
            if(D[s] == INF) continue;
            if(D[e] > D[s] + w){
                D[e] = D[s] + w;
                B[e] = s;
                isChanged = true;
            }
            if(isChanged && iter == V){
                cycle = true;
                cy.push_back(s);
                cy.push_back(e);
            }
        }
    }
    sort(cy.begin(), cy.end());
    cy.erase(unique(cy.begin(), cy.end()), cy.end());
    do{
        if(binary_search(cy.begin(), cy.end(), V)){
            cout << -1 << "\n";
            return 0;
        }
        ans.push_back(V);
        V = B[V];
    }while(V != 0);
    reverse(ans.begin(), ans.end());
    for(auto x : ans) cout << x << " ";
    cout << "\n";
    return 0;
}