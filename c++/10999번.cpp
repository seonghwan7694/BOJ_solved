#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SIZE 1000001

vector<ll> arr(SIZE), tree(SIZE * 4), lazy(SIZE * 4);
ll N, M, K;

ll init(int node, int start, int end){
    if(start == end) return tree[node] = arr[start];
    return tree[node] = init(node * 2, start, (start + end)/2) + init(node * 2 + 1, (start + end)/2 + 1, end);
}

void update_lazy(ll node, ll start, ll end){
    if(lazy[node] != 0){
        tree[node] += (end - start + 1) * lazy[node];
        if(start != end){
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update_range(ll node, ll left, ll right, ll start, ll end, ll diff){
    update_lazy(node, start, end);
    if(start > right or end < left) return;
    if(left <= start and end <= right){
        tree[node] += (end - start + 1) * diff;
        if(start != end){
            lazy[node * 2] += diff;
            lazy[node * 2 + 1] += diff;
        }
        return;
    }
    update_range(node * 2, left, right, start, (start + end)/2, diff);
    update_range(node * 2 + 1, left, right, (start + end)/2 + 1, end, diff);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll sum(ll node, ll left, ll right, ll start, ll end){
    update_lazy(node, start, end);
    if(start > right or end < left) return 0;
    if(left <= start and end <= right) return tree[node];
    return sum(node * 2, left, right, start, (start + end)/2) + sum(node *2 +1,left,right,(start+end)/2+1, end);
}


int main(){
    ios::sync_with_stdio(false);
    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    init(1, 1, N);
    for(int i = 0, a, b, c, d; i < M + K; i++){
        cin >> a;
        if(a == 1){
            cin >> b >> c >> d;
            // [b, c] += d
            update_range(1, b, c, 1, N, d);
        }else{
            cin >> b >> c;
            cout << sum(1, b, c, 1, N) << "\n";
            // print sum of [b, c]
        }

    }



    return 0;
}