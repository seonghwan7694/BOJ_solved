#include <bits/stdc++.h>
using namespace std;

int N, K, s[50505], dp[4][50505];

int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1, tmp; i <= N; i++){
        cin >> tmp;
        s[i] = s[i-1] + tmp;
    }
    cin >> K;
    // v[n] - v[n-k] => n n - 1 ... n - k + 1
    for(int i = 1; i <= 3; i++){
        for(int j = i * K; j <= N; j++){
            dp[i][j] = max(dp[i][j-1], dp[i-1][j-K] + s[j] - s[j-K]);
        }
    }
    cout << dp[3][N] << "\n";
    return 0;
}