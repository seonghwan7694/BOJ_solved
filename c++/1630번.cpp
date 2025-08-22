#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define MAX_SIZE 100'000'001ll
#define MOD (1ll << 32)
bool isComposite[MAX_SIZE];
vector<ll> p;
ll N, R = 1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(ll i = 2; i <= N; i++){
        if(isComposite[i]) continue;
        for(ll j = i * i; j <= N; j += i){
            isComposite[j] = true;
        }
    }
    for(ll i = 2; i <= N; i++){
        if(!isComposite[i]) p.push_back(i);
    }
    for(auto x : p){
        if(x > N) break;
        ll k = x;
        while(k * x <= N)k *= x, k %= MOD;
        R = (R * k) % MOD;
    }
    cout << R << "\n";
    return 0;
}