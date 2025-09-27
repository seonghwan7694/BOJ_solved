#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 202'202

int dp[MAX_SIZE], N, R, Q; // dp[v] : v를 루트로 하는 서브트리에서 속한 정점의 수
vector<int> g[MAX_SIZE];
bool vis[MAX_SIZE];

int func(int r){
    for(auto c : g[r]){
        if(vis[c]) continue;
        vis[c] = true;
        dp[r] += func(c);
    }
    return dp[r];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> R >> Q;
    for(int i = 0, u, v; i < N - 1; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= N; i++) dp[i] = 1;

    vis[R] = true;
    func(R);
    
    while(Q--){
        int tmp;
        cin >> tmp;
        cout << dp[tmp] << "\n";
    }


    return 0;
}