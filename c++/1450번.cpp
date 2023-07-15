#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
using namespace std;
#define lld long long int
lld N, C;
vector<int> bag;

void dfs(int st, int en, lld sum, vector<lld> &list){
    if(st > en){
        list.push_back(sum);
        return;
    }else{
        dfs(st + 1, en, sum, list);
        dfs(st + 1, en, sum + bag[st], list);
    }
}

int main(){
    ios::sync_with_stdio(false);
    
    cin >> N >> C;
    bag.resize(N, 0);
    for(int i = 0; i < N; i++){
        cin >> bag[i];
    }
    vector<lld> l1, l2;
    dfs(0, N/2 - 1, 0, l1); // [0, N/2)
    dfs(N/2, N - 1, 0, l2); // [N/2, N)
    sort(l2.begin(), l2.end());
    int ans = 0;
    for(int i = 0; i < l1.size(); i++){
        lld x = C - l1[i];
        ans += upper_bound(l2.begin(), l2.end(), x) - l2.begin();
    }
    cout << ans << "\n";
    return 0;
}