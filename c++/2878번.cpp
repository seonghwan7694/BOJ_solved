#include <bits/stdc++.h>
using namespace std;
#define lld long long int
lld M, N, sum, ans;

int main(){
    ios::sync_with_stdio(false);
    cin >> M >> N;
    vector<lld> v(N);
    sum = -M;
    for(int i = 0; i < N; i++){
        cin >> v[i];
        sum += v[i];
    }
    sort(v.begin(), v.end(), less<int>());
    for(int i = 0; i < N; i++){
        lld w = min((lld) v[i], (lld) sum/(N - i));
        ans += w * w;
        sum -= w;
    }
    cout << ans << "\n";
    return 0;
}