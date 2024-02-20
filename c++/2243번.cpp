#include <bits/stdc++.h>
using namespace std;
#define SIZE 1010101
int n;

vector<long long> tree;

void update(int node, int idx, int st, int en, int diff){
    if(idx < st or idx > en) return;
    tree[node] += diff;
    int mid = (st + en)/2;
    if(st != en){
        update(node * 2, idx, st, mid, diff);
        update(node * 2 + 1, idx, mid + 1, en, diff);
    }
}

int get_candy(int node, int st, int en, int rank){
    if(st == en) return st;
    int mid = (st + en)/2;
    if(tree[node * 2] >= rank){
        return get_candy(node * 2, st, mid, rank);
    }else{
        return get_candy(node * 2 + 1, mid + 1, en, rank - tree[node * 2]);
    }
}

vector<long long> res;

int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    tree = vector<long long >(5*SIZE);

    for(int i = 0, A, B, C; i < n; i++){
        cin >> A;
        if(A == 1){
            cin >> B; // pick B-th candy
            int taste = get_candy(1, 1, SIZE, B);
            res.push_back(taste);
            update(1, taste, 1, SIZE, -1);
        }else{
            cin >> B >> C;
            update(1, B, 1, SIZE, C);
        }
    }
    for(auto &x : res) cout << x << "\n";
    return 0;
}