#include <bits/stdc++.h>
using namespace std;

long long N, K, A[101], D[2][10101];

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }
    // D[i][*] = D[i-1][* - A[j]]
    D[0][0] = 1;
    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= K; j++){ D[i%2][j] = 0;
            for(int c = 0; j - c * A[i] >= 0; c++){
                D[i%2][j] += D[(i-1)%2][j - c * A[i]];
            }
        }
    }
    cout << D[N%2][K] << "\n";
    return 0;
}