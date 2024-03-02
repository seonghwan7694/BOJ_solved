#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll N, M;
struct node{
    int u1, u2;
    node(int u1, int u2){
        this->u1 = u1;
        this->u2 = u2;
    }
};

vector<node> v;

const int SIZE = 2000;
ll seg[4 * (SIZE + 10)];

ll sum(int node, int start, int end, int left, int right){
    if(end < left or right < start){
        return 0;
    }   
    if(left <= start and end <= right){
        return seg[node];
    }
    int mid = (start + end)/2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int idx, ll val){
    if(start > idx or idx > end) return;
    seg[node] += val;
    if(start != end){
        int mid = (start + end)/2;
        update(node * 2, start, mid, idx, val);
        update(node * 2 + 1, mid + 1, end, idx, val);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> M;
    while(M--){
        int u1, u2;
        cin >> u1 >> u2;
        u1++, u2++;
        struct node n(u1, u2);
        v.push_back(n);
    }
    sort(v.begin(), v.end(), [](node v1, node v2){
        if(v1.u1 == v2.u1){
            return v1.u2 < v2.u2;
        }
        return v1.u1 < v2.u1;
    });
    // cout << "\n\n"; for(auto x : v){ cout << x.u1 << " " << x.u2 << "\n"; } cout << "\n\n";
    ll res = 0;
    for(auto &x : v){
        res += sum(1, 1, N, x.u2, N);
        update(1, 1, N, x.u2 - 1, 1);
    }
    cout << res << "\n";
    return 0;
}