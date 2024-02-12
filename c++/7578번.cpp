#include <bits/stdc++.h>
using namespace std;

int N, F[1010101];
vector<int> arr, tree;
long long int res;

void update(int node, int st, int en, int idx, int diff){
    if(idx < st or en < idx) return;
    tree[node] += diff;
    if(st != en){
        update(node * 2, st, (st + en)/2, idx, diff);
        update(node * 2+1, (st + en)/2 + 1, en, idx, diff);
    }
}

long long sum(int idx, int left, int right, int st, int en){ // get sum [left, right]
    if(st > right or en < left) return 0;
    if(left <= st and en <= right) return tree[idx]; // 탐색하는 범위가 포함되는 경우   
    return sum(idx * 2, left, right, st, (st + en)/2) + sum(idx * 2 + 1, left, right, (st + en)/2 + 1, en);

}

int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    arr = vector<int>(N + 10);
    tree = vector<int>(4 * (N + 10));
    for(int i = 1, t; i <= N; i++){
        cin >> t;
        F[t] = i; // store i
    }
    for(int i = 1, t; i <= N; i++){
        cin >> t;
        arr[i] =  F[t]; // store value 't' is when presented
    }
    for(int i = 1; i <= N; i++){
        // visit arr[i], count thing which is visited right-side
        int j = arr[i];
        res += sum(1, j + 1, N, 1, N);
        update(1, 1, N, j, 1);
    }
    cout << res << "\n";
    return 0;
}