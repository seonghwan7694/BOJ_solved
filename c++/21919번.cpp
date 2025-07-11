#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define MAX_N 1010101
ll gcd(ll a, ll b){
    ll tmp;
    while(b > 0){
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

ll lcm(ll a, ll b){
    return a * b / gcd(a, b);
}

ll N, ret = 1;
vector<bool> isPrime(MAX_N * 3, true);
int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    isPrime[0] = isPrime[1] = false;
    for(ll i = 2; i <= 1'000'000; i++){
        if(isPrime[i] == false) continue;
        for(ll j = i * i; j <= 1'000'000; j += i){
            isPrime[j] = false;
        }
    }
    for(ll i = 0, tmp; i < N; i++){
        cin >> tmp;
        if(isPrime[tmp]){
            ret = lcm(tmp, ret);
        }
    }
    cout << (ret == 1 ? -1 : ret) << "\n";
    return 0;
}