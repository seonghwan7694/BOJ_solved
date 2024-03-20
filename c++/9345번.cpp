#include <bits/stdc++.h>
using namespace std;
#define SIZE 101010
#define pii pair<int, int>
#define INF INT32_MAX
int T, N, K, Q, A, B, loc[SIZE]; 
pii seg[SIZE * 4];
vector<int> ans;

void init(int node, int start, int end){
    if(start == end){
        seg[node] = {start, start};
        return;
    }
    int mid = (start + end)/2;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);
    pii &l = seg[node * 2];
    pii &r = seg[node * 2 + 1];
    seg[node] = {min(l.first, r.first), max(l.second, r.second)};
    return;
}

void update(int node, int start, int end, int idx, int val){
    if(idx < start or end < idx) return;
    if(start == end){
        seg[node] = {val, val};
        return;
    }
    int mid = (start + end)/2;
    update(node * 2, start, mid, idx, val);
    update(node * 2 + 1, mid + 1, end, idx, val);
    pii &l = seg[node * 2];
    pii &r = seg[node * 2 + 1];
    seg[node] = {min(l.first, r.first), max(l.second, r.second)};
    return;
}

pii query(int node, int start, int end, int left, int right){
    if(end < left or right < start) return {INF, -INF};
    if(left <= start and end <= right) return seg[node];
    int mid = (start + end)/2;
    pii l = query(node * 2, start, mid, left, right);
    pii r = query(node * 2 + 1, mid + 1, end, left, right);
    return {min(l.first, r.first), max(l.second, r.second)};
}

vector<pii> tmp;
void solution(){
    cin >> N >> K;
    iota(loc, loc + SIZE, 0);
    init(1, 1, N);
    while(K--){
        cin >> Q >> A >> B;
        A++, B++;

        if(Q == 0){
            update(1, 1, N, A, loc[B]);
            update(1, 1, N, B, loc[A]);
            swap(loc[A], loc[B]);
        }else{
            pii res = query(1, 1, N, A, B);
            tmp.push_back(res);
            if(res.first == A and res.second == B){
                ans.push_back(1);
            }else{
                ans.push_back(0);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--){
        solution();
    }

    for(auto &x : ans){
        if(x == 1){
            cout << "YES" << "\n";
        }else{
            cout << "NO" << "\n";
        }
    }
    // for(auto &[a, b] : tmp){ cout << a << " " << b << "\n"; }
    return 0;
}