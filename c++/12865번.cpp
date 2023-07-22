#include <bits/stdc++.h>
using namespace std;

int N, K, D[101][101010];

// 1..i번째물건을적당히선택해서무게의합이j일때가능한가치의최댓
int main(){
    ios::sync_with_stdio(false);
    cin >> N >> K;
    vector<pair<int, int>> v(N + 1);
    for(int i = 1, W, C; i <= N; i++){
        cin >> W >> C;
        v[i] = {W, C};
    }
    for(int i = 1 ; i <= N; i++){
        for(int j = 1; j <= K; j++){
            auto [W, C] = v[i];
            if(j - W >= 0)D[i][j] = max(D[i-1][j], D[i-1][j - W] + C);
            else D[i][j] = D[i-1][j];
        }
    }
    cout << D[N][K] << "\n";
    return 0;
}