#include <bits/stdc++.h>
using namespace std;
#define SIZE 505050
int N, M, t, a, b, c, arr[SIZE], tree[SIZE * 4], lazy[SIZE * 4];
vector<int> ans;

int init(int node, int st, int en){
    if(st == en){
        return tree[node] = arr[st];
    }
    int mid = (st + en)/2;
    return tree[node] = init(node * 2, st, mid) ^ init(node * 2 + 1, mid + 1, en);
}

void update_lazy(int node, int st, int en){
    if(lazy[node] != 0){
        if((en - st + 1) % 2 == 1) tree[node] ^= lazy[node];
        if(st != en){
            lazy[node * 2] ^= lazy[node];
            lazy[node * 2 + 1] ^= lazy[node];
        }
        lazy[node] = 0;
    }
    return;
}

void update_range(int node, int st, int en, int left, int right, int val){
    update_lazy(node, st, en);
    if(en < left or right < st) return;
    if(left <= st and en <= right){
        lazy[node] ^= val;
        update_lazy(node, st, en);
        return;
    }
    int mid = (st + en)/2;
    update_range(node * 2, st, mid, left, right, val);
    update_range(node * 2 + 1, mid + 1, en, left, right, val);
    tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
    return;
}
int sum(int node, int start, int end, int left, int right){
    update_lazy(node, start, end);
    if(left > end or right < start) return 0; 
    if(left <= start and end <= right and start == end) return tree[node];
    int mid = (start + end)/2;
    int res1 = sum(node * 2, start, mid, left, right);
    int res2 = sum(node * 2 + 1, mid + 1, end, left, right);
    return res1 ^ res2;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    init(1, 1, N);
    cin >> M;
    while(M--){
        cin >> t;
        if(t == 1){
            cin >> a >> b >> c;
            a++, b++;
            update_range(1, 1, N, a, b, c);
        }else{
            cin >> a;
            a++;
            ans.push_back(sum(1, 1, N, a, a));
        }
    }
    for(auto &x : ans) cout << x << "\n";
    return 0;
}