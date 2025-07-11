#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

ll x, n;
vector<ll> l;

int main(){
    ios::sync_with_stdio(false);
    while(cin >> x){ // cm
        x *= 10'000'000; // nm
        cin >> n; // N of Bricks
        l = vector<ll>(n);
        for(int i = 0; i < n; i++){
            cin >> l[i];
        }
        sort(l.begin(), l.end());
        int s = 0, e = n - 1;
        while(s < e){
            if(l[s] + l[e] == x){
                cout << "yes " << l[s] << " " << l[e] << "\n";
                break;
            }else if(l[s] + l[e] > x) e--;
            else s++;
        }
        if(s >= e) cout << "danger" << "\n";
    }
    return 0;
}