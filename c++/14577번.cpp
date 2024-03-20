#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SIZE 101010
#define pll pair<ll, ll>
ll N, M, L, R, A[SIZE], op, island_idx, snow, T;
#define SNOW_MIN 0
#define SNOW_MAX 1000000000000000100
pll tree[SIZE * 4];
ll tree2[SNOW_MAX];

void update(ll node, ll start, ll end, ll idx, ll val){
    if(idx < start or end < idx) return;
    if(start == idx and idx == end){
        tree[node] = {val, val};
        return;
    }
    if(start == end) return;
    ll mid = (start + end)/2;
    update(node * 2, start, mid, idx, val);
    update(node * 2 + 1, mid + 1, end, idx, val);
    pll &le = tree[node * 2];
    pll &ri = tree[node * 2 + 1];
    tree[node] = {min(le.first, ri.first), max(le.second, ri.second)};
}

void update2(ll node, ll s, ll e, ll snow, ll diff){
    if(s == e){ tree2[node] += diff; return; }
    ll m = (s + e) >> 1;
    if(snow <= m){
        update2(node * 2, s, m, snow, diff);
    }else{
        update2(node * 2 + 1, m + 1, e, snow, diff);
    }
    tree2[node] = tree2[node * 2] + tree2[node * 2 + 1];
    return;
}

ll query4(ll node, ll s, ll e, ll kth){
    if(s == e) return s;
    ll l = tree2[node * 2], m = (s + e) >> 1;
    if(kth <= l){
        return query4(node * 2, s, m, kth);
    }
    return query4(node * 2, m + 1, e, kth - l);
}

pll init(ll node, ll start, ll end){
    if(start == end){
        if(A[start] == -1) return tree[node] = {INT64_MAX, INT64_MIN};
        return tree[node] = {A[start], A[start]};
    }
    ll mid = (start + end)/2;
    pll le = init(node * 2, start, mid);
    pll ri = init(node * 2 + 1, mid + 1, end);
    return {min(le.first, ri.first), max(le.second, ri.second)};
}

ll query3(ll node, ll st, ll en){
    ll l = tree[node].first, r = tree[node].second;
    if(R < l or r < L) return 0;
    if(L <= l and r <= R){
        return (en - st + 1);
    }
    ll mid = (st + en)/2;
    return query3(node * 2, st, mid) + query3(node * 2 + 1, mid + 1, en);
}

int main(){
    ios::sync_with_stdio(false);

    cin >> N >> M;
    fill(A, A + SIZE, -1);
    for(int i = 1; i <= N; i++){
        cin >> A[i];
        update2(1, SNOW_MIN, SNOW_MAX, A[i], 1);
    }
    init(1, 1, N);
    vector<ll> res;
    while(M--){
        cin >> op;
        if(op == 1){
            cin >> island_idx >> snow;
            // update2(1, SNOW_MIN, SNOW_MAX, A[island_idx], -1);
            A[island_idx] += snow;
            // update2(1, SNOW_MIN, SNOW_MAX, A[island_idx], 1);
            update(1, 1, N, island_idx, A[island_idx]);
        }else if(op == 2){
            cin >> island_idx >> snow;
            // update2(1, SNOW_MIN, SNOW_MAX, A[island_idx], -1);
            A[island_idx] -= snow;
            // update2(1, SNOW_MIN, SNOW_MAX, A[island_idx], 1);
            update(1, 1, N, island_idx, A[island_idx]);
        }else if(op == 3){
            cin >> L >> R;
            res.push_back(query3(1, 1, N));
        }else{
            cin >> T;
            // res.push_back(query4(1, SNOW_MIN, SNOW_MAX, N - T + 1));
        }
    }
    for(auto &x : res) cout << x << "\n";
    return 0;
}