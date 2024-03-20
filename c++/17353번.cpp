#include <bits/stdc++.h>
using namespace std;
#define SIZE 101010
#define ll long long 

ll N, arr[SIZE], seg[SIZE * 4], lazy[SIZE * 4], Q, op, L, R, X;



void update_lazy(ll node, ll start, ll end){
    if(lazy[node] != 0){
        ll mid = (start + end)/2;
        seg[node] += lazy[node] * (end - start + 1);
        if(start != end){
            int mid = (start + end)/2;
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
        return;
    }
}

void update_range(ll node, ll start, ll end, ll left, ll right, ll val){
    update_lazy(node, start, end);

    if(end < left or right < start) return;

    if(left <= start and end <= right){
        seg[node] += val * (end - start + 1);
        if(start != end){
            lazy[node * 2] += val;
            lazy[node * 2 + 1] += val;
        }
        return; 
    }
    ll mid = (start + end)/2;
    update_range(node * 2, start, mid, left, right, val);
    update_range(node * 2 + 1, mid + 1, end, left, right, val);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
    return;
}

ll get(int node, int start, int end, int left, int right){
    update_lazy(node, start, end);
    if(left > end || right < start) return 0;
    if(left <= start and end <= right) return seg[node];
    ll mid = (start + end)/2;
    return get(node * 2, start, mid, left, right) + get(node * 2 + 1, mid + 1, end, left, right); 
}

vector<ll> ans;
int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    for(int i = 1; i <= N; i++) update_range(1, 1, N, i, i, arr[i] - arr[i - 1]);
    cin >> Q;
    while(Q--){
        cin >> op;
        if(op == 1){
            cin >> L >> R;
            update_range(1, 1, N, L, R, 1);
            update_range(1, 1, N, R + 1, R + 1, -(R - L + 1));

        }else{
            cin >> X;
            ans.push_back(get(1, 1, N, 1, X));
        }
    }
    for(auto &x : ans) cout << x << "\n";
    return 0;
}