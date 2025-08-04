#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX_N 1'000'001
bool isComposite[MAX_N] = {};

long long POW(long long a, long long n){
    return pow(a, n);
}

long long Phi(long long n){
    long long cpy_n = n, ret = 1;
    for(long long i = 2, sub_ret; i < MAX_N; i++){
        if(isComposite[i]) continue;
        sub_ret = 0;

        while(cpy_n % i == 0){
            cpy_n /= i;
            sub_ret++;
        }

        if(sub_ret == 1) ret *= i - 1;
        else{
            ret *= POW(i, sub_ret) - POW(i, sub_ret - 1);
        }
    }
    if(cpy_n != 1) ret *= cpy_n - 1;
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    long long n;

    for(long long i = 2; i < MAX_N; i++){
        if(isComposite[i]) continue;
        for(long long j = i * i; j < MAX_N; j += i){
            isComposite[j] = true;
        }
    }
    cin >> n;
    cout << Phi(n) << "\n";
    return 0;
}