#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX_SIZE 202020
ll N, W[MAX_SIZE];
vector<ll> g[MAX_SIZE];
vector<pair<ll, ll>> edge;
ll dp[MAX_SIZE][2], ans = INT64_MIN;
// dp[i][0] : i를 루트로하고, i를 포함하지 않을 때 최댓값
// dp[i][1] : i를 루트로하고, i를 포함할 때 최댓값
// 정답 : dp[u][1] + max(dp[pu][0], dp[pu][1])

void func(int cur){ 

    if(g[cur].size() == 1) return;

    for(auto next : g[cur]){
        if(cur > next) continue;
        func(next);
        if(dp[next][1] > 0) dp[cur][1] += dp[next][1];
        dp[cur][0] = max(dp[cur][0], dp[next][1]);
        dp[cur][0] = max(dp[cur][0], dp[next][0]);
    }
}

ll find_ans(int u, int pu){
    ll tmp_ans = W[pu];
    for(auto cu : g[pu]){ // pu를 루트로 하면서, 그 경로에 u가 없는 것을 탐색
        if(cu == u) continue;
        if(dp[cu][1] > 0) tmp_ans += dp[cu][1];
    }
    for(auto cu : g[pu]){
        if(cu == u) continue;
        tmp_ans = max({tmp_ans, dp[cu][0]});
    }
    return tmp_ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 1, w, pi; i <= N; i++){
        cin >> w >> pi;
        W[i] = w; 
        dp[i][1] = w;
        if(i > 1){
            g[pi].push_back(i);
            g[i].push_back(pi);
            edge.push_back({i, pi});
        }
    }
    func(1);
    for(auto [u, pu] : edge){
        ans = max(ans, dp[u][1] + find_ans(u, pu));
        cout << "@ u: " << u << " pu: " << pu << ", " << dp[u][1] << " " << find_ans(u, pu) << "\n";
    }
    
    // for(int i = 1; i <= N; i++){ cout << i << " : " << dp[i][0] << " " << dp[i][1] << "\n"; }
    cout << ans << "\n";
}