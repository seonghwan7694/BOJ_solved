#include <bits/stdc++.h>
using namespace std;

int value_to_idx[1010101], N;
vector<long long> tree, arr;
long long res;

long long int sum(int node, int left, int right, int st, int en){ // get sum [left, right]
    if(en < left or right < st) return 0;
    if(left <= st and en <= right) return tree[node];
    return sum(node * 2, left, right, st, (st +en )/2) + sum(node * 2 + 1, left, right, (st+en)/2+1, en);
}

void update(int node, int st, int en, int arr_idx, int diff){
    if(!(st <= arr_idx and arr_idx <= en)) return;
    tree[node] += diff;
    if(st != en){
        update(node*2, st, (st+en)/2, arr_idx, diff);
        update(node*2+1, (st+en)/2+1, en, arr_idx, diff);
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    arr = vector<long long>(N + 10);
    tree = vector<long long>(4*(N+10));
    for(int i = 1, t; i <= N; i++){
        cin >> t;
        value_to_idx[t] = i;
    }

    for(int i = 1; i <= N; i++){
        int j = value_to_idx[i];
        res += sum(1, j + 1, N, 1, N);
        update(1, 1, N, j, 1);
    }
    cout << res << "\n";
    return 0;
}