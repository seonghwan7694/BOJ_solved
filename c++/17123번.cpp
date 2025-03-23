#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int T;

void solve(){
    int N, M;
    cin >> N >> M;
    vector<ll> row(N + 1, 0), col(N + 1, 0);

    for(int i = 1; i <= N; i++){
        for(int j = 1, tmp; j <= N; j++){
            cin >> tmp;
            row[i] += tmp;
            col[j] += tmp;
        }
    }
    int r1, c1, r2, c2, v;
    while(M--){
        cin >> r1 >> c1 >> r2 >> c2 >> v;
        // 행
        for(int i = r1; i <= r2; i++){
            row[i] += v * (c2 - c1 + 1);
        }
        // 열
        for(int i = c1; i <= c2; i++){
            col[i] += v * (r2 - r1 + 1);
        }
    }
    for(int i = 1; i <= N; i++) cout << row[i] << " ";
    cout << "\n";
    for(int i = 1; i <= N; i++) cout << col[i] << " ";
    cout << "\n";
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}