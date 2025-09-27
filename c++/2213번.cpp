#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 10101

// dp[v][0] : v를 루트로 하는 서브트리에서 v를 선택하지 않을 때 최대 독립 집합
// dp[v][1] : v를 루트로 하는 서브트리에서 v를 선택했을 때 최대 독립 집합
int dp[MAX_SIZE][2];
int N, W[MAX_SIZE];
vector<int> g[MAX_SIZE], ans;
bool vis[MAX_SIZE], flag;
void func(int r){
    if(vis[r]) return;
    vis[r] = true;
    for(auto c : g[r]){
        if(vis[c]) continue;
        func(c);
        dp[r][0] += max(dp[c][1], dp[c][0]); 
        dp[r][1] += dp[c][0];
    }
    dp[r][1] += W[r];
}

void backtrack(int cur, int prev, bool state){
    if(state){
        ans.push_back(cur);
        for(auto next : g[cur]){
            if(next == prev) continue;
            backtrack(next, cur, 0);
        }
    }else{
        for(auto next : g[cur]){
            if(next == prev) continue;
            if(dp[next][1] >= dp[next][0]) backtrack(next, cur, 1);
            else backtrack(next, cur, 0);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> W[i];
    for(int i = 1, u, v; i < N; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    func(1);
    cout << max(dp[1][0], dp[1][1]) << "\n";
    fill(vis, vis + MAX_SIZE, false);
    if(dp[1][1] >= dp[1][0]) backtrack(1, -1, 1);
    else backtrack(1, -1, 0);
    sort(ans.begin(), ans.end());
    for(auto x : ans) cout << x <<  " ";
    cout << "\n";
    return 0;
}