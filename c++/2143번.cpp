#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define lld long long int

lld T, A[1000], B[1000], n, ans, m;
vector<lld> v, v2;

int main(){
    ios::sync_with_stdio(false);
    cin >> T;
    cin >> n;
    for(int i = 0; i < n; i++){ cin >> A[i]; }
    cin >> m;
    for(int i = 0; i < m; i++){ cin >> B[i]; }

    for(int i = 0; i < n; i++){
        long long sum = A[i];
        v.push_back(sum);
        for(int j = i + 1; j < n; j++){
            sum += A[j];
            v.push_back(sum);
        }
    }
    for(int i = 0; i < m; i++){
        long long sum = B[i];
        v2.push_back(sum);
        for(int j = i + 1; j < m; j++){
            sum += B[j];
            v2.push_back(sum);
        }
    }
    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end());
    for(int i = 0; i < v.size(); i++){
        int high = upper_bound(v2.begin(), v2.end(), T - v[i]) - v2.begin();
        int low = lower_bound(v2.begin(), v2.end(), T - v[i]) - v2.begin();
        ans += high - low;
    }
    cout << ans << "\n";
    return 0;
}