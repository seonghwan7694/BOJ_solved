#include <bits/stdc++.h>
using namespace std;
#define lld long long int
#define MAX_SIZE 1010101
lld N, M, K; // M : change number, K : get SUM
lld arr[MAX_SIZE], segmentTree[MAX_SIZE * 4], lazy[MAX_SIZE * 4];

lld makeSegmentTree(lld node, lld start, lld end){
    if(start == end){
        return segmentTree[node] = arr[start];
    }
    lld mid = (start + end)/2;
    return segmentTree[node] = makeSegmentTree(node * 2, start, mid) + makeSegmentTree(node * 2 + 1, mid + 1, end);
}

void update_lazy(lld node, lld start, lld end){
    if(lazy[node] != 0){
        segmentTree[node] += (end - start + 1) * lazy[node];
        if(start != end){
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}


void update_range(lld node, lld start, lld end, lld l, lld r, lld val){
    update_lazy(node, start, end);
    if(l > end or r < start) return;
    if(l <= start and end <= r){
        segmentTree[node] += (end - start + 1) * val;
        if(start != end){
            lazy[node * 2] += val;
            lazy[node * 2 + 1] += val;
        }   
        return;
    }
    lld mid = (start + end) / 2;
    update_range(node * 2, start, mid, l, r, val);
    update_range(node * 2 + 1, mid + 1, end, l, r, val);
    segmentTree[node] = segmentTree[node * 2] + segmentTree[node * 2 + 1];
}


lld query(lld node, lld start, lld end, lld l, lld r){ // sum of [l, r]
    update_lazy(node, start, end);
    if(l > end or r < start) return 0;

    if(l <= start and end <= r) return segmentTree[node];

    lld mid = (start + end) / 2;
    return query(node * 2, start, mid, l, r) + query(node * 2 + 1, mid + 1, end, l , r);
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> M >> K;
    for(lld i = 1, tmp; i <= N; i++){
        cin >> tmp;
        arr[i] = tmp;
    }
    makeSegmentTree(1, 1, N);
    for(lld i = 0, a, b, c, d; i < M + K; i++){
        cin >> a;
        if(a == 1){
            cin >> b >> c >> d;
            update_range(1, 1, N, b, c, d);
        }else{
            cin >> b >> c;
            cout << query(1, 1, N, b, c) << "\n";
        }
    }
    return 0;
}