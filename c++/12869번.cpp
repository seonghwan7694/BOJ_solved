#include <bits/stdc++.h>
#include <tuple>
using namespace std;
int N;
int dp[61][61][61];
tuple<int, int, int> t[6] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 9, 1},
    {3, 1, 9},
    {1, 3, 9},
    {1, 9, 3}
};

int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    vector<int> A(3);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = 0; i <= 60; i++){
        for(int j = 0; j <= 60; j++){
            for(int k = 0; k <= 60; k++){
                dp[i][j][k] = 10101;
            }
        }
    }

    queue<tuple<int, int, int, int>> q;
    q.push(make_tuple(A[0], A[1], A[2], 0));

    while(!q.empty()){
        auto [a, b, c, cnt] = q.front();
        q.pop();
        if(a == 0 and b == 0 and c == 0) break;
        for(int i = 0; i < 6; i++){
            auto [d1, d2, d3] = t[i];
            int na = a - d1 > 0 ? a - d1 : 0;
            int nb = b - d2 > 0 ? b - d2 : 0;
            int nc = c - d3 > 0 ? c - d3 : 0;
            if(dp[na][nb][nc] != 10101) continue;
            dp[na][nb][nc] = cnt + 1; 
            q.push(make_tuple(na, nb, nc, cnt + 1));
        }
    }
    cout << dp[0][0][0] << "\n";
    return 0;
}