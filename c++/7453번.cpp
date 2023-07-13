#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define lld long long int

lld n;
int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    lld arr[n][4];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            cin >> arr[i][j]; 
        }
    }
    lld res = 0;
    vector<lld> sum1;
    vector<lld> sum2;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            sum1.push_back(arr[i][0] + arr[j][1]);
            sum2.push_back(arr[i][2] + arr[j][3]);
        }
    }
    sort(sum1.begin(), sum1.end());
    sort(sum2.begin(), sum2.end());
    for(int i = 0; i < sum1.size(); i++){
        int idx = lower_bound(sum2.begin(), sum2.end(), -sum1[i]) - sum2.begin();
        int endIdx = upper_bound(sum2.begin(), sum2.end(), -sum1[i]) - sum2.begin();
        res += endIdx - idx;
    }
    cout << res << "\n";
    return 0;
}