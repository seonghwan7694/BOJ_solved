#include <bits/stdc++.h>
#define lld long long int
using namespace std;

lld N, L;

bool AreDoubleSame(double dFirstVal, double dSecondVal)
{
    return std::fabs(dFirstVal - dSecondVal) < 1E-3;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> L;
    while(L <= 100){
        if(N % L == 0 and L % 2 == 1){
            for(lld i = N/L - L/2; i <= N/L + L/2; i++){
                if(i < 0){ cout << -1 << "\n"; return 0; }
                cout << i << " ";
            }
            cout << "\n";
            return 0;
        }
        if(AreDoubleSame((double)N/L - N/L, 0.5L) and L % 2 == 0){
	        for(lld i = N/L - L/2 + 1; i <= N/L + L/2; i++){
                if(i < 0){ cout << -1 << "\n"; return 0; }
                cout << i << " ";
            }
            cout << "\n";
            return 0;
        }
        L++;
    }

    cout << -1 << "\n";
    return 0;
}