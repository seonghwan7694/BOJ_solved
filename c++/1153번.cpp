#include <iostream>
#include <vector>
using namespace std;
#define MAX_SIZE 1'000'111
#define ll long long
bool isPrime[MAX_SIZE];
vector<ll> prime;
ll N;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(ll i = 2; i <= N; i++){
        if(isPrime[i]) continue;
        for(ll j = i * i; j <= N; j += i) isPrime[j] = true;
    }
    for(ll i = 2; i <= N; i++){
        if(!isPrime[i]) prime.push_back(i);
    }
    for(auto a = prime.begin(); a != prime.end(); a++){
        for(auto b = a; b != prime.end(); b++){
            for(auto c = a; c != prime.end(); c++){
                if(binary_search(prime.begin(), prime.end(), N - (*a + *b + *c))){
                    cout << *a << " " << *b << " " << *c << " " << N - (*a + *b + *c) << "\n";
                    return 0;
                }
            }
        }
    }
    cout << -1 << "\n";
    return 0;
}