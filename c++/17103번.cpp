#include <iostream>
#include <vector>
using namespace std;
#define MAX_SIZE 1000101
#define ll long long
bool isPrime[MAX_SIZE];
vector<ll> p, ans;
int main(){
    ll T, N, cnt;
    cin >> T;
    fill(isPrime, isPrime + MAX_SIZE, true);
    for(ll i = 2; i < MAX_SIZE; i++){
        if(!isPrime[i]) continue;
        for(ll j = i * i; j < MAX_SIZE; j += i){
            isPrime[j] = false;
        }
    }
    for(int i = 2; i < MAX_SIZE; i++){
        if(isPrime[i]) p.push_back(i);
    }
    while(T--){
        cin >> N;
        cnt = 0;
        for(auto x : p){
            if(2 * x > N) break;
            if(binary_search(p.begin(), p.end(), N - x)) cnt++;
        }
        ans.push_back(cnt);
    }
    for(auto x : ans){
        cout << x << "\n";
    }
}