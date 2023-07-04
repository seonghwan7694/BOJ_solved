#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1000];
int dp[1000];

int func(int idx){
    if(idx == N) return 0;

    int &res = dp[idx];
    if(res != -1) return res;

    res = 0;
    int low = 101010, high = -1;
    for(int i = idx; i < N; i++){
        low = min(low, arr[i]);
        high = max(high, arr[i]);
        res = max(res, (high - low) + func(i + 1));
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    memset(dp, -1, sizeof dp);
    cout << func(0) << "\n";
    return 0;
}