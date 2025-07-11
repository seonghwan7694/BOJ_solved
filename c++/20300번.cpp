#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long

ll N, ret;
vector<ll> T;
int main(){
    cin >> N;
    T = vector<ll>(N);
    for(int i = 0; i < N; i++){
        cin >> T[i];
    }
    sort(T.begin(), T.end());

    ll l = 0, r = N - 1;
    if(N % 2 == 1){
        ret = T[r--];
    }
    while(l < r){
        ret = max(ret, T[l++] + T[r--]);
    }
    cout << ret << "\n";
}