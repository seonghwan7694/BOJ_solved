#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll N, M, A, B, C, T;
ll dp[51][1001];

ll S(int i, int t){
    if(i < 0 or i >= N) return 0;
    if(dp[i][t] != -1) return dp[i][t];
    if(t == 0) return dp[i][t];
    // t >= 1
    if(i - 1 >= 0 and dp[i - 1][t - 1] == -1) dp[i - 1][t - 1] = S(i - 1, t - 1) % M;
    
    ll a = (A % M) * (S(i - 1, t - 1) % M);
    ll b = (B % M) * (S(i, t - 1) % M);
    ll c = (C % M) * (S(i + 1, t - 1) % M);
    return (dp[i - 1][t - 1] + dp[i][t - 1] + dp[i + 1][t - 1]) % M;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(true){
        cin >> N >> M >> A >> B >> C >> T;
        if(N == 0 and M == 0 and A == 0 and B == 0 and C == 0 and T == 0) break;
        fill(&dp[0][0], &dp[0][0] + 51 * 1001, -1);
        for(int i = 0; i < N; i++) cin >> dp[i][0];

    }


    return 0;
}