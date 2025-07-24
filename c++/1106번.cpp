#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_SIZE 100001

int dp[MAX_SIZE]; // dp[c] = p : c원을 사용했을 때 얻을 수 있는 고객의 수
int C, N;

int main(){
    ios::sync_with_stdio(false);
    cin >> C >> N;
    vector<pair<int, int>> v(N);
    for(int i = 0; i < N; i++){
        cin >> v[i].first;
        cin >> v[i].second;
    }
    for(int i = 0; i < N; i++){
        for(int j = 1; j <= 100000; j++){
            auto [cost, people] = v[i];
            if(j - cost >= 0) dp[j] = max(dp[j], dp[j - cost] + people);
        }
    }
    cout << (int) (lower_bound(dp, dp + MAX_SIZE, C) - dp) << "\n";
    return 0;
}