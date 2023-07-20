#include <bits/stdc++.h>
using namespace std;
#define lld long long int

// ((a mod n) * (b mod n))mod n = (a * b) mod n

lld func(lld N, lld P){
    lld res = 1;
    for(lld i = 1; i <= N; i++){
        res *= i;
        res %= P;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    lld N, P;
    cin >> N >> P;
    cout << func(N, P) << "\n";
    return 0;
}