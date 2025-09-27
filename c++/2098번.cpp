#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
int N, W[16][16], dp[16][1 << 16], T, ans = INF;

int func(int u, int t){
    if(t == T){
        if(W[u][0] != 0){
            return W[u][0];
        }else{
            return INF;
        }
    }

    int &ret = dp[u][t];
    if(ret != -1) return ret; 

    ret = INF;
    for(int i = 0; i < N; i++){
        if((~t & (1 << i)) and W[u][i] != 0){
            int nt = t | (1 << i);
            ret = min(ret, func(i, nt) + W[u][i]);
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    T = (1 << N) - 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> W[i][j];
    }
    memset(dp, -1, sizeof(dp));
    cout << func(0, 1) << "\n";
    return 0;
}