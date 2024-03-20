#include <bits/stdc++.h>
using namespace std;
#define SIZE 1010101
int N, M, arr[SIZE], seg[SIZE * 4];

void init(int node, int start, int end){
    if(start == end){
        seg[node] = arr[start];
        return;
    }
    int mid = (start + end)/2;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);
    seg[node] = max(seg[node * 2], seg[node * 2 + 1]);
    return;
}
int update(int node, int start, int end, int idx, int val){
    if(idx < start or end < idx) return -1;
    if(start == end){
        return seg[node] = val;
    }
    int mid = (start + end)/2;
    int l = update(node * 2, start, mid, idx, val);
    int r = update(node * 2 + 1, mid + 1, end, idx, val);
    return seg[node] = max(l, r);
}

int query(int node, int start, int end, int left, int right){
    if(end < left or right < start) return -1;
    if(left <= start and end <= right) return seg[node];
    int mid = (start + end)/2;
    int l = query(node * 2, start, mid, left, right);
    int r = query(node * 2 + 1, mid + 1, end, left, right);
    return max(l, r);
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    init(1, 1, N);
    for (int i = M; i <= (N - M) + 1; i++) {
		cout << query(1, 1, N, i - M + 1, i + M - 1) << " ";
	}
	cout << "\n";
    return 0;
}