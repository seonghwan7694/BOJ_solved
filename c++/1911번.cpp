#include <bits/stdc++.h>
using namespace std;

int N, L, s, e, ans; // last : 마지막으로 널빤지를 놓은 위치
vector<pair<int, int>> P;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> L;
    for(int i = 0, l, r; i < N; i++){
        cin >> l >> r;
        P.push_back({l, r}); // 구간 [l, r)에 웅덩이가 있다.
    }
    sort(P.begin(), P.end());
    s = P[0].first, e = P[0].first + L;
    for(auto [l, r] : P){
        if(s < l){
            s = l;
            e = l + L;
        }
        while(s < r){
            ans++;
            s = e;
            e = s + L;
        }
    }
    cout << ans << "\n";
    return 0;
}