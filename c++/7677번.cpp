#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 10000
int n;

void mtp(vector<vector<int>> &a, vector<vector<int>> &b){
    vector<vector<int>> tmp(2, vector<int>(2, 0));
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(true){
        cin >> n;
        if(n == -1) break;

        vector<vector<int>> ret = {{1, 0}, {0, 1}};
        vector<vector<int>> a = {{1, 1}, {1, 0}};
        while(n > 0){
            if(n % 2){
                mtp(ret, a);
            }
            mtp(a, a);
            n >>= 1;
        }
        cout << ret[0][1] % mod << "\n";
    }
}