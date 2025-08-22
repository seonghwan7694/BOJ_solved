#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define MAX_SIZE 1'000'001

int T, N;
vector<ll> g(MAX_SIZE, 1);
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    g[0] = 0;
    for(ll i = 2; i < MAX_SIZE; i++){
        for(ll j = i; j < MAX_SIZE; j += i) g[j] += i;
    }

    for(int i = 1; i < MAX_SIZE; i++){
        g[i] += g[i - 1];
    }
    while(T--){
        cin >> N;
        cout << g[N] << "\n";
    }
}