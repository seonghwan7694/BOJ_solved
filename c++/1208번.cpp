#include <bits/stdc++.h>
#include <unordered_map>
#define lld long long int
using namespace std;
vector<int> v;
unordered_map<int, int> um;
lld half, res;
lld N, S;

void dfs_left(int idx, int sum){
    if(idx == half){
        um[sum]++;
        return;
    }
    dfs_left(idx + 1, sum + v[idx]);
    dfs_left(idx + 1, sum);
    return;
}

void dfs_right(int idx, int sum){
    if(idx == N){
        res += um[S - sum];
        return;
    }

    dfs_right(idx + 1, sum + v[idx]);
    dfs_right(idx + 1, sum);
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin >> N >> S;
    half = N / 2;
    v.resize(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    dfs_left(0, 0);
    dfs_right(half, 0);
    if(S == 0) res--;
    cout << res << "\n";

    return 0;
}