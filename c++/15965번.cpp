#include <bits/stdc++.h>
using namespace std;
#define lld long long int
#define MAX_N 7500000
bool isPrime[MAX_N + 1];

int main(){
    ios::sync_with_stdio(false);
    lld K;
    cin >> K;
    memset(isPrime, true, sizeof isPrime);
    for(lld i = 2; i <= MAX_N; i++){
        for(lld j = i * i; j <= MAX_N; j+=i){
            isPrime[j] = false;
        }
    }
    lld cnt = 0;
    for(lld i = 2; i <= MAX_N; i++){
        if(isPrime[i]) cnt++;
        if(cnt == K){
            cout << i << "\n";
            break;
        }
    }
    lld k = 0;
    



    return 0;
}