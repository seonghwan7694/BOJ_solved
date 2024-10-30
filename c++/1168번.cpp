#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SIZE 101010
ll tree[SIZE * 4], N, K;

void print(vector<ll> &v){
    cout << "<";
    for(auto iter = v.begin();iter != v.end(); iter++){
        cout << *iter;
        if(iter + 1 != v.end()) cout << ", ";
        else cout << ">\n";
    }
    return;
}

ll query(ll n, ll s, ll e, ll k){
    tree[n]--;
    if(s == e) return s;
    ll lc = tree[n * 2];
    ll m = (s + e) >> 1;
    if(k <= lc){
        return query(n * 2, s, m, k);
    }else{
        return query(n * 2 + 1, m + 1, e, k - lc);
    }
}

ll init(ll n, ll s, ll e){
    if(s == e){
        return tree[n] = 1;
    }
    ll m = (s + e) >> 1;
    return tree[n] = init(n * 2, s, m) + init(n * 2 + 1, m + 1, e);
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> K;
    vector<ll> ans(N, 0);
    ll idx = K - 1;
    init(1, 1, N);
    for(ll i = 0; i < N; i++){
        ll ret = query(1, 1, N, idx + 1);
        ans[i] = ret;
        idx += K - 1;
        if(tree[1] == 0) break;
        idx %= tree[1];
    }
    print(ans);
    return 0;
}