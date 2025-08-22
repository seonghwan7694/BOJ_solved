#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
#define MAX_SIZE 1010101
#define ll long long
ll N;
bool isPrime[MAX_SIZE];

bool func(ll n){
    stringstream ss;
    ss << n;
    string s = ss.str();
    string rs(s.begin(), s.end());
    reverse(rs.begin(), rs.end());
    return s == rs;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    fill(isPrime, isPrime + MAX_SIZE, true);
    isPrime[1] = false;
    for(ll i = 2; i < MAX_SIZE; i++){
        if(!isPrime[i]) continue;
        for(ll j = i * i; j < MAX_SIZE; j += i){
            isPrime[j] = false;
        }
    }
    for(ll n = N; n < MAX_SIZE; n++){
        if(isPrime[n] && func(n)){
            cout << n << "\n";
            break;
        }
    }



    return 0;
}