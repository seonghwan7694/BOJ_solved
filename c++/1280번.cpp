#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>

const ll MOD = 1000000007, MAX_N = 210000;
ll cnt[4 * (MAX_N + 10)], dist[4 * (MAX_N + 10)];
ll N, ans = 1;


void update(ll n, ll s, ll e, ll i){
    if(i < s or e < i) return;
    if(s == e){
        cnt[n]++;
        dist[n] += i;
        return;
    }
    ll m = (s + e) >> 1;
    update(n * 2, s, m, i);
    update(n * 2 + 1, m + 1, e, i);
    cnt[n] = cnt[n * 2] + cnt[n * 2 + 1];
    dist[n] = dist[n * 2] + dist[n * 2 + 1];
    return;
}

pll query(ll n, ll s, ll e, ll le, ll ri){
    if(ri < s or e < le) return {0, 0}; 
    if(le <= s and e <= ri){
        return {cnt[n], dist[n]};
    }
    ll m = (s + e) >> 1;
    pll l = query(n * 2, s, m, le, ri);
    pll r = query(n * 2 + 1, m + 1, e, le, ri);
    return {l.first + r.first, l.second + r.second};
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    ll tmp, ret;
    pll l, r;
    cin >> tmp;
    update(1, 0, MAX_N - 1, tmp);
    for(ll i = 1; i < N; i++){
        cin >> tmp;
        l = query(1, 0, MAX_N - 1, 0, tmp - 1);
        r = query(1, 0, MAX_N - 1, tmp + 1, MAX_N - 1);
        ret = abs(tmp * l.first - l.second) + abs(r.second - tmp * r.first);
        ans %= MOD;
        ans *= ret % MOD;
        update(1, 0, MAX_N - 1, tmp);
    }
    cout << ans % MOD << "\n";
    return 0;
}