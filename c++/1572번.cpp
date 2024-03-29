#include <bits/stdc++.h>
using namespace std;
#define SIZE 65535
#define ll unsigned long long

ll N, K, A[SIZE], tree[SIZE * 4], ans;

void update(ll n, ll s, ll e, ll i, ll v){
    if(i < s or e < i) return;
    if(s == e){
        tree[n] += v;
        return;
    }
    ll m = (s + e) >> 1;
    update(n * 2, s, m, i, v);
    update(n * 2 + 1, m + 1, e, i, v);
    tree[n] = tree[n * 2] + tree[n * 2 + 1];
}

ll query(ll n, ll s, ll e, ll k){
    if(s == e) return s;
    ll m = (s + e) >> 1;
    ll l = tree[n * 2];
    if(k <= l) return query(n * 2, s, m, k);
    return query(n * 2 + 1, m + 1, e, k - l);
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> K;
    for(ll i = 1; i <= N; i++){
        cin >> A[i];
        if(i < K){
            update(1, 0, SIZE, A[i], 1);
        }
    }
    for(ll i = K, j = 1; i <= N; i++, j++){
        update(1, 0, SIZE, A[i], 1);
        ans += query(1, 0, SIZE, (K + 1)/2);
        update(1, 0, SIZE, A[j], -1);
    }
    cout << ans << "\n";
    return 0;
}