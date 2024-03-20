#include <bits/stdc++.h>
using namespace std;
#define SIZE 101010
int N, M, arr[SIZE], seg[SIZE * 4], O, S, T;
bool lazy[SIZE * 4];
vector<int> ans;

void update_lazy(int node, int start, int end){
    if(lazy[node] != 0){
        seg[node] = (end - start + 1) - seg[node];
        if(start != end){
            lazy[node * 2] = !lazy[node * 2];
            lazy[node * 2 + 1] = !lazy[node * 2 + 1];
        }
        lazy[node] = 0;
    }
    return;
}

void update_range(int node, int start, int end, int left, int right, int val){
    update_lazy(node, start, end);
    if(right < start or end < left) return;
    if(left <= start and end <= right){
        seg[node] = (end - start + 1) - seg[node];
        if(start != end){
            lazy[node * 2] = !lazy[node * 2];
            lazy[node * 2 + 1] = !lazy[node * 2 + 1];
        }
        return;
    }
    int mid = (start + end)/2;
    update_range(node * 2, start, mid, left, right, val);
    update_range(node * 2 + 1, mid + 1, end, left, right, val);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
    return;
}

int sum(int node, int start, int end, int left, int right){
    update_lazy(node, start, end);
    if(right < start or end < left) return 0;
    if(left <= start and end <= right) return seg[node];
    
    int mid = (start + end)/2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}
int main(){
    ios::sync_with_stdio(false);
    cin >> N >> M;
    while(M--){
        cin >> O >> S >> T;
        if(O == 0){
            update_range(1, 1, N, S, T, 1);
        }else{
            ans.push_back(sum(1, 1, N, S, T));
        }
    }
    for(auto &x : ans) cout << x << "\n";



    return 0;
}