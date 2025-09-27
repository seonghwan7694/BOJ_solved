#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1'000'000'000ll
ll n;

void mtp(vector<vector<ll>> &a, vector<vector<ll>> &b){
    vector<vector<ll>> tmp(2, vector<ll>(2, 0));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                tmp[i][j] += (a[i][k] * b[k][j]) % mod;
            }
        }
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            a[i][j] = tmp[i][j] % mod;
        }
    }
    return;
}

ll fibo_n(ll n){
    vector<vector<ll>> ret = {{1, 0}, {0, 1}};
    vector<vector<ll>> a = {{1, 1}, {1, 0}};
    while(n > 0){
        if(n % 2){
            mtp(ret, a);
        }
        mtp(a, a);
        n >>= 1;
    }
    return ret[0][1];
}

ll a, b;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a >> b;
    cout << (fibo_n(b + 2) - fibo_n(a + 1) + mod) % mod << "\n";
}