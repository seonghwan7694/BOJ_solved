#include <bits/stdc++.h>
using namespace std;
int N, ans;
int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    vector<int> P(N);
    for(int i = 0; i < N; i++){
        cin >> P[i];
    }
    sort(P.begin(), P.end());
    for(int i = 0, tmp = 0, sum = 0; i < N; i++){
        tmp = sum + P[i];
        sum += P[i];
        ans += tmp;
    }
    cout << ans << "\n";
    return 0;
}