#include <bits/stdc++.h>
using namespace std;
#define lld long long int
lld N, K;
lld LOW, HIGH, MID;
lld cnt;

lld less_than(lld idx){
    lld res = 0;
    for(int i = 1; i <= N; i++){
        res += min(N, idx/i);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> K;

    K = min((lld) 1000000000, K);   
    LOW = 1, HIGH = N * N;
    while(LOW <= HIGH){
        MID = (LOW + HIGH) / 2;
        cnt = less_than(MID);
        if(K <= cnt){
            HIGH = MID - 1;
        }else{
            LOW = MID + 1;
        }
    }

    cout << LOW << "\n";
    return 0;
}