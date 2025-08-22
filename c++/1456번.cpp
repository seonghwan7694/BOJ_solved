#include <iostream>
#include <vector>
using namespace std;
#define ll unsigned long long
#define MAX_SIZE 10'000'001ull
ll A, B, ret;
bool isPrime[MAX_SIZE];
vector<ll> p;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> A >> B;
    fill(isPrime, isPrime + MAX_SIZE, true);
    for(ll i = 2; i < MAX_SIZE; i++){
        if(!isPrime[i]) continue;
        for(ll j = i * i; j < MAX_SIZE; j += i) isPrime[j] = false;
    }
    for(ll i = 2; i < MAX_SIZE; i++){
        if(isPrime[i]) p.push_back(i);
    }
    for(ll x : p){
        ll cpy_x = x;
        while(cpy_x <= B / x){
            cpy_x *= x;
            if(cpy_x >= A) ret++;
        }
    }
    cout << ret << "\n";
    return 0;
}