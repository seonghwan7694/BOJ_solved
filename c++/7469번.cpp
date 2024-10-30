#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define all(v) v.begin(), v.end()
const ll SIZE = 101010;
ll N, Q, A[SIZE];
vector<ll> t[SIZE * 3];

void update(ll n, ll s, ll e, ll x, ll v){
    if(x < s or e < x) return;
    t[n].push_back(v);
    if(s != e){
        ll m = (s + e) >> 1;
        update(n * 2, s, m, x, v);
        update(n * 2 + 1, m + 1, e, x, v);
    }
}

ll query(ll n, ll s, ll e, ll l, ll r, ll k){
    if(e < l or r < s) return 0;
    ll m = (s + e) >> 1;
    if(l <= s and e <= r){
        return upper_bound(t[n].begin(), t[n].end(), k) - t[n].begin();
    }
    return query(n * 2, s, m, l, r, k) + query(n * 2 + 1, m + 1, e, l, r, k);
}

vector<ll> ret;

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> Q;
    for(ll i = 1; i <= N; i++){
        cin >> A[i];
        update(1, 1, N, i, A[i]);
    }
    for(ll i = 0; i < SIZE * 2; i++){
        sort(t[i].begin(), t[i].end());
    }   
    ll i, j, k;
    while(Q--){
        cin >> i >> j >> k;
        ll l = -1e9, r = 1e9, m = 0;
        while(l <= r){
            m = (l + r) >> 1;
            if(query(1, 1, N, i, j, m) < k) l = m + 1;
            else r = m - 1;
        }
        ret.push_back(l);
    }
    for(auto &x : ret){
        cout << x << "\n";
    }
    return 0;
}