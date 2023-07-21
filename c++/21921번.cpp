#include <bits/stdc++.h>
using namespace std;
#define lld long long int

lld X, N, ans;

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> X;
    vector<lld> A(N + 1);
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }
    lld st = 1, en = X, window = 0;
    for(int i = st; i <= en; i++){
        window += A[i];
    }
    ans = max(ans, window);
    int dd = 1;
    while(en != N){
        window += -A[st++] + A[++en];
        if(ans == window){
            dd++;
        }else if(window > ans){
            ans = window;
            dd = 1;
        }

    }
    if(ans == 0){
        cout << "SAD" << "\n";
        return 0;
    }
    cout << ans << "\n";
    cout << dd << "\n";
    return 0;
}