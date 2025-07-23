#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
ll D, T;
vector<ll> ans;
ll d[202], t[202];
ll p[202]; // p[d1] = d2 : d1에 도착하기 전에 d2를 들려야함.
ll dp[202]; // dp[d] = {d에 도착하기 위한 최소 정비시간}

int main(){
    ios::sync_with_stdio(false);
    fill(dp, dp + 199, INT32_MAX * 3ll);

    cin >> D >> T;
    for(ll i = 1, tmp; i <= T + 1; i++){
        cin >> d[i];
        d[i] += d[i - 1];
    }

    for(ll i = 1, tmp; i <= T; i++){
        cin >> t[i];
    }

    dp[0] = 0;
    for(ll i = 1; i <= T + 1; i++){
        for(ll j = i - 1; j >= 0; j--){
            if(d[i] - d[j] > D) break;
            if(dp[i] > dp[j] + t[j]){
                dp[i] = dp[j] + t[j];
                p[i] = j;
            }
        }
    }
    cout << dp[T + 1] << "\n";
    
    ll now = T + 1;
    while(p[now]){
        ans.push_back(p[now]);
        now = p[now];
    }
    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    if(ans.size() == 0) return 0;
    for(auto x : ans) cout << x << " ";
    cout << "\n";
    return 0;
}