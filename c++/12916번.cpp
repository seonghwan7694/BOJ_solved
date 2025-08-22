#include <bits/stdc++.h>
using namespace std;
const long long mod = 1'000'000'007;

long long A[51][51], N, M, K, ret[51][51];

void matrix_product(long long (*a)[51], long long (*b)[51]){
    long long tmp[51][51];
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            tmp[i][j] = 0;
            for(int k = 1; k <= N; k++){
                tmp[i][j] += (a[i][k] * b[k][j]);
                tmp[i][j] %= mod;
            }
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            a[i][j]= tmp[i][j];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for(int m = 0, i, j; m < M; m++){
        cin >> i >> j;
        A[i][j] = 1;
        A[j][i] = 1;
    }
    cin >> K;
    for(int i = 0; i < N; i++) ret[i][i] = 1;
    while(K > 0){
        if(K % 2 == 1){
            matrix_product(ret, A);
        }
        matrix_product(A, A);
        K /= 2;
    }
    cout << ret[1][1] % mod << "\n";
    return 0;
}