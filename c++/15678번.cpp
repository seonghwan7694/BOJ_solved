#include <bits/stdc++.h>
using namespace std;
#define lld long long int
#define MAX_N 100000 + 1
lld N, D, K, DP, RES = -1e18-5050;

int main(){
    ios::sync_with_stdio(false);

    cin >> N >> D;
    deque<pair<lld, lld>> dq;
    for(int i = 0; i < N; i++){
        cin >> K;
        while(dq.size() and dq.front().second < i - D) dq.pop_front();
        lld dp = K;
        if(dq.size()) dp = max(dp, dp + dq.front().first);
        RES = max(dp, RES);
        while(dq.size() and dq.back().first <= dp) dq.pop_back();
        dq.push_back({dp, i});
    }
    cout << RES << "\n";
    return 0;
}