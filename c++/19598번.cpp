#include <bits/stdc++.h>
using namespace std;
int N, ans = 1;
priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int, int>> v;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 0, s, e; i < N; i++){
        cin >> s >> e;
        v.push_back({s, e});
    }
    sort(v.begin(), v.end());
    pq.push(v[0].second);
    for(int i = 1; i < N; i++){
        auto [s, e] = v[i];
        while(!pq.empty() and s >= pq.top()) pq.pop();
        pq.push(e);
        ans = max(ans, (int) pq.size());
    }
    cout << ans << "\n";
    return 0;
}