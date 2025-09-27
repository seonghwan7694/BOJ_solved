#include <bits/stdc++.h>
using namespace std;
#define line pair<int, int>
int n, L, ans;
priority_queue<int, vector<int>, greater<int>> pq;
vector<line> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0, s, e; i < n; i++){
        cin >> s >> e;
        if(s > e) swap(e, s);
        v.push_back({s, e});
    }
    cin >> L;
    sort(v.begin(), v.end(), [](auto &a, auto &b){
        if(a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    });

    for(int i = 0; i < n; i++){
        int s = v[i].first, e = v[i].second;
        if(e - s > L) continue;
        pq.push(s);
        while(!pq.empty()){
            if(pq.top() + L >= e){
                ans = max(ans, (int) pq.size());
                break;
            }else{
                pq.pop();
            }
        }
    }
    cout << ans << "\n";
    return 0;
}