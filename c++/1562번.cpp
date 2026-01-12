#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define MOD 1'000'000'000

ll N, dp[101][10], ans; // dp[len][E] : 길이가 len이고 끝자리 숫자가 E인 계단 수의 개수이다.
// dp[len][e] = dp[len - 1][(e + 1)%10] + dp[len - 1][(e - 1 + 10)%10] % MOD
// 1234567890

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i <= 9; i++){
        dp[1][i] = 1;
    }
    for(int len = 2; len <= 100; len++){
        for(int e = 0; e <= 9; e++){
            dp[len][e] = dp[len - 1][(e + 1)%10] + dp[len - 1][(e - 1 + 10)%10];
            dp[len][e] %= MOD;
        }
    }
    ll tmp_ans = 0;
    for(int len = 1; len <= 40; len++){
        for(int e = 0; e <= 9; e++){
            tmp_ans += dp[len][e] % MOD;
        }
    }
    cout << tmp_ans << "\n";
    for(int e = 0; e <= 9; e++) ans += dp[N][e], ans %= MOD;
    cout << ans << "\n";
    return 0;
    // 1212343456789
}