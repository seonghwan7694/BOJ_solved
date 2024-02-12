#include <bits/stdc++.h>
using namespace std;

int N, M, K;
unsigned long long dp[105][105];
bool road[105][105][2];

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> M >> K;
    for(int i = 0, x1, y1, x2, y2; i < K; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        if(y1 != y2) road[x1][min(y1, y2)][1] = true;
        if(x1 != x2) road[min(x1, x2)][y1][0] = true;
    }
    dp[0][0] = 1;
    for(int x = 0; x <= N; x++){
        for(int y = 0; y <= M; y++){
            if(!road[x][y][1]){
                dp[x][y+1] += dp[x][y];
            }
            if(!road[x][y][0]){
                dp[x+1][y] += dp[x][y];
            }
        }
    }
    cout << dp[N][M] << "\n";
    return 0;
}