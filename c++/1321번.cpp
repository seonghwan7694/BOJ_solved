#include <vector>
#include <iostream>
using namespace std;
#define ll long long
#define MAX_SIZE 505050
ll N, A[MAX_SIZE], M, cmd, a, b, seg[MAX_SIZE * 4];

void init(int v, int s, int e){
    if(s == e){
        seg[v] = A[s]; 
        return;
    }
    ll m = (s + e) >> 1;
    init(v * 2, s, m);
    init(v * 2 + 1, m + 1, e);
    seg[v] = seg[v * 2] + seg[v * 2 + 1];
    return;
}

void update(int v, int s, int e, int i, int a){
    if(i < s or e < i) return;
    seg[v] += a;
    if(s == e) return;
    ll m = (s + e) >> 1;
    update(v * 2, s, m, i, a);
    update(v * 2 + 1, m + 1, e, i, a);
}

ll query(int v, int s, int e, int i){
    if(s == e) return s;
    ll m = (s + e) >> 1;
    if(seg[v * 2] < i){
        return query(v * 2 + 1, m + 1, e, i - seg[v * 2]);
    }
    return query(v * 2, s, m, i);
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];
    init(1, 1, N);
    cin >> M;
    while(M--){
        cin >> cmd;
        if(cmd == 1){
            cin >> a >> b;
            update(1, 1, N, a, b);
        }else{
            cin >> a;
            cout << query(1, 1, N, a) << "\n";
        }
    }
    return 0;
}