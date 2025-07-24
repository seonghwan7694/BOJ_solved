#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_M 
int T;
int N, M;
vector<int> ans;
void solution(){
    cin >> N;
    vector<int> coin(N);
    for(int i = 0; i < N; i++) cin >> coin[i];
    cin >> M;
    int dp[M + 1]; // dp[m] = cnt : m원을 방법의 수 cnt
    fill(dp, dp + M + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < N; i++){
        for(int j = 1; j <= M; j++){
            if(j - coin[i] >= 0) dp[j] += dp[j - coin[i]];
        }
    }
    ans.push_back(dp[M]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        solution();
    }
    for(auto &x : ans) cout << x << "\n";
    return 0;
}