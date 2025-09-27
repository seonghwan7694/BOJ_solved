#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 10101
// dp[v][0] : v를 루트로 하는 서브트리에서 정점 v를 우수마을로 선정하지 않았을 때 값
// dp[v][1] : v를 루트로 하는 서브트리에서 정점 v를 우수마을로 선정할 때 값
int dp[MAX_SIZE][2], N, residence[MAX_SIZE];
vector<int> g[MAX_SIZE];
bool vis[MAX_SIZE];

void func(int r){
    if(vis[r]){
        dp[r][0] = 0;
        dp[r][1] = residence[r];
        return;
    }

    vis[r]  =true;

    dp[r][1] += residence[r];
    for(auto c : g[r]){
        if(vis[c]) continue;
        func(c);
        dp[r][0] += max(dp[c][1], dp[c][0]);
        dp[r][1] += dp[c][0];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> residence[i];
    for(int i = 1, u, v; i < N; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    func(1);
    cout << max(dp[1][0], dp[1][1]) << "\n";
}