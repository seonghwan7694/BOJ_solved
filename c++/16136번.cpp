#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 1111
#define ll long long

bool isPrime[MAX_SIZE];
vector<int> prime;
ll N, Q;
ll seg[MAX_SIZE * MAX_SIZE * 4], A[MAX_SIZE * MAX_SIZE];

void init(int n, int s, int e){
    if(s == e){
        seg[n] = A[s];
        return;
    }
    int m = (s + e) >> 1;
    init(n * 2, s, m);
    init(n * 2 + 1, m + 1, e);
    seg[n] = seg[n * 2] + seg[n * 2 + 1];
    return;
}

void io(){
    cin >> N >> Q;
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }
    fill(isPrime, isPrime + MAX_SIZE, true);
    for(int i = 2; i < MAX_SIZE; i++){
            if(!isPrime[i]) continue;
        for(int j = i * i; j < MAX_SIZE; j += i){
            isPrime[j] = false;
        }
    }
    for(int i = 2; i < MAX_SIZE; i++) if(isPrime[i]) prime.push_back(i);
}

int count_divisors(int n){
    int ret = 1;
    for(auto p : prime){
        if(n == 1) break;
        int power = 0;
        while(n % p == 0){
            n /= p;
            power++;
        }
        ret *= (power + 1);
    }
    return ret;
}

void update(int n, int s, int e, int idx, int val){
    if(idx < s or e < idx) return;
    seg[n] += val;
    if(s == e) return;
    int m = (s + e) >> 1;
    update(n * 2, s, m, idx, val);
    update(n * 2 + 1, m + 1, e, idx, val);
}

int query(int n, int s, int e, int l, int r){
    if(e < l or r < s) return 0;
    if(l <= s and e <= r) return seg[n];
    int m = (s + e) >> 1;
    return query(n * 2, s, m, l, r) + query(n * 2 + 1, m + 1, e, l, r);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    io();
    init(1, 1, N);
    ll T, S, E;
    while(Q--){
        cin >> T >> S >> E;
        if(T == 1){
            for(int i = S; i <= E; i++){
                int new_Ai = count_divisors(A[i]);
                update(1, 1, N, i, new_Ai - A[i]);
                A[i] = new_Ai;
            }
        }else{
            cout << query(1, 1, N, S, E) << "\n";
        }
    }


    return 0;
}