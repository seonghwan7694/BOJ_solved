#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll N, T, X;
#define SIZE 2020202
ll tree[SIZE * 4];


void update(ll node, ll s, ll e, ll idx, ll val){
    if(idx < s or e < idx) return;
    if(s == e){
        tree[node] += val;
        return;    
    }
    ll m = (s + e) >> 1;
    update(node * 2, s, m, idx, val);
    update(node * 2 + 1, m + 1, e, idx, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(ll node, ll s, ll e, ll kth){
    if(s == e) return e;
    ll l = tree[node * 2];
    ll m = (s + e) >> 1;
    if(kth <= l){
        return query(node * 2, s, m, kth);
    }
    return query(node * 2 + 1, m + 1, e, kth - l);
}

vector<ll> ans;
int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    while(N--){
        cin >> T >> X;
        if(T == 1){
            update(1, 1, SIZE, X, 1);
        }else{
            ll val = query(1, 1, SIZE, X);
            update(1, 1, SIZE, val, -1);
            ans.push_back(val);
        }
    }
    for(auto &x : ans) cout << x << "\n";
    return 0;
}