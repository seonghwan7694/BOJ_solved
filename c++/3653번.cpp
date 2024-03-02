#include <bits/stdc++.h>
using namespace std;
#define SIZE 101010

int t;
int n, m;
int seg[8 * SIZE], arr[8 * SIZE];

int sum(int node, int start, int end, int left, int right){
    if(end < left or right < start) return 0;
    if(left <= start and end <= right){
        return seg[node];
    }
    int mid = (start + end)/2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int idx, int diff){
    if(idx < start or end < idx) return;
    seg[node] += diff;
    if(start != end){
        int mid = (start + end)/2;
        update(node * 2, start, mid, idx, diff);
        update(node * 2 + 1, mid + 1, end, idx, diff);
    }
}

void solve(){
    cin >> n >> m;
    memset(seg, 0, sizeof seg);
    memset(arr, 0, sizeof arr);
    for(int i = m + 1; i <= n + m; i++){
        update(1, 1, n + m, i, 1);
        arr[i - m] = i;
    }

    vector<int> v(m);
    for(int i = 0; i < m; i++){
        cin >> v[i];
    }
    int idx = m;
    for(auto &x : v){
        cout << sum(1, 1, n + m, 1, arr[x] - 1) << " ";
        update(1, 1, n + m, arr[x], -1);
        arr[x] = idx--;
        update(1, 1, n + m, arr[x], 1);
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}