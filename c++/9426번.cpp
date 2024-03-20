#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SIZE 252525
#define TEMP_MIN 0
#define TEMP_MAX 65535
ll N, K, A[SIZE], temp_to_idx[SIZE], tree[SIZE * 4], ret;

void update(int node, int s, int e, int temp, int diff){
    if(s == e){tree[node] += diff; return;}
    int m = (s + e) >> 1;
    if(temp <= m){
        update(node * 2, s, m, temp, diff);
    }else{
        update(node * 2 + 1, m + 1, e, temp, diff);
    }
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
    return;
}

ll query(int node, int s, int e, int kth){
    if(s == e) return s;
    int m = (s + e) >> 1;
    int l = tree[node * 2];
    if(kth <= l){
        return query(node * 2, s, m, kth);
    }
    return query(node * 2 + 1, m + 1, e, kth - l);
}
vector<ll> res;
int main(){
    ios::sync_with_stdio(false);
    cin >> N >> K;
    for(int i = 1, idx; i <= N; i++){
        cin >> A[i];
        if(i <= K) update(1, TEMP_MIN, TEMP_MAX, A[i], 1);
    }
    ll mid_idx = (1 + K) >> 1;
    for(int i = K + 1; i <= N; i++){
        ret += query(1, TEMP_MIN, TEMP_MAX, (1 + K) >> 1);
        res.push_back(query(1, TEMP_MIN, TEMP_MAX, mid_idx));
        update(1, TEMP_MIN, TEMP_MAX, A[i - K], -1);
        update(1, TEMP_MIN, TEMP_MAX, A[i], 1);
    }
    ret += query(1, TEMP_MIN, TEMP_MAX, (1 + K) >> 1);
    cout << ret << "\n";
    // for(auto &x : res) cout << x << " ";
    return 0;
}