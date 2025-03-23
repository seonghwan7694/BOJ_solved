#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 50'000 * 4
#define pii pair<int , int>
#define x first
#define y second
int N, Q, A, B;

vector<pii> seg_tree(MAX_SIZE * 4, {INT32_MAX, INT32_MIN}); // {min, max}
vector<int> height;

pii init_tree(int n, int l, int r){
    if(l == r){
        return seg_tree[n] = {height[l], height[l]};
    }
    int m = (l + r) >> 1;
    pii ln = init_tree(n * 2, l, m);
    pii rn = init_tree(n * 2 + 1, m + 1, r);
    return seg_tree[n] = {min(ln.x, rn.x), max(ln.y, rn.y)};
}

pii query(int n, int l, int r, int s, int e){
    if(e < l or r < s) return {INT32_MAX, INT32_MIN};
    if(s <= l and r <= e) return seg_tree[n];
    int m = (l + r) >> 1;
    pii lq = query(n * 2, l, m, s, e);
    pii rq = query(n * 2 + 1, m + 1, r, s, e);
    return {min(lq.x, rq.x), max(lq.y, rq.y)};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> Q;
    height.resize(N + 1);
    for(int i = 1; i <= N; i++){
        cin >> height[i];
    }
    init_tree(1, 1, N);
    while(Q--){
        cin >> A >> B;
        pii res = query(1, 1, N, A, B);
        cout << res.y - res.x << "\n";
    }
    return 0;
}