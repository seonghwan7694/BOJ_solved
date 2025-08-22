#include <iostream>
#include <vector>
using namespace std;
#define ll long long
ll N;
bool c[555'555];

ll POW(int n){
    ll ret = 1;
    while(n--){
        ret *= 3;
    }
    return ret;
}

void func(ll s, ll e, ll n, bool flag){ // 구간 [s, e]
    if(n == 0){
        c[s] = flag;
        return;
    }

    int m1 = s + POW(n - 1) - 1, m2 = s + 2 * POW(n - 1) - 1;
    func(s, m1, n - 1, flag);
    func(m1 + 1, m2, n - 1, false);
    func(m2 + 1, e, n - 1, flag);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> N){
        fill(c, c + 555'555, false);
        func(1, (ll) POW(N), N, true);
        for(ll i = 1; i <= POW(N); i++){
            cout << (c[i] ? '-' : ' ');
        }
        cout << "\n";
    }
    return 0;
}