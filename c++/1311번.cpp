#include <bits/stdc++.h>
using namespace std;

int w[20][20], N, dp[1 << 20]; // dp[19...0] : n번째 비트가 1이면, 해당 일을 한 상태. 누가했는지?

// dp[i][19...j...0] 
int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> w[i][j];
        }
    }
    for(int i = 0; i < (1 < 20); i++){

    }
    return 0;
}