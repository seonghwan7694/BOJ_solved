#include <bits/stdc++.h>
using namespace std;
#define ll long long
int N, X[100001], R[1000001];
bool is_Num[1000001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> X[i], is_Num[X[i]] = true;
    ll a, b;
    for(int i = 1; i <= N; i++){
        for(int j = X[i] + X[i]; j < 1000001; j += X[i]){
            if(is_Num[j] == false) continue;
            R[X[i]]++;
            R[j]--;
        }
    }
    for(int i = 1; i <= N; i++){
        cout << R[X[i]] << " ";
    }
    cout << "\n";
    return 0;
}