#include <bits/stdc++.h>
using namespace std;
#define lld unsigned long long int

lld L = 0, R, MID;
lld n;

int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    // the smallest q with 'q^2 >= n' 
    R = sqrt(n) + 1;
    while(L < R){ // {L, R}
        MID = (L + R)/2;
        // cout << L << " " << R << "\n";
        if(MID >= sqrt(n)){ // search left-side
            R = MID - 1;
        }else{ // search right-side
            L = MID + 1;
        }
    }
    for(lld i = R; i < R + 3; i++){
        if(i * i >= n){
            cout << i << "\n";
            break;
        }
    }
    return 0;
}