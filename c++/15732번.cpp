#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define lld long long int

lld N, K, D;
vector<lld> A, B, C;

bool func(lld last_box_number){
    lld can_put_D = 0;
    for(int i = 0; i < K; i++){
        if(last_box_number < A[i]) continue;
        can_put_D += ceil((min(B[i], last_box_number) - A[i])/C[i]) + 1;
    }
    
    if(can_put_D >= D) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> K >> D;                                                                                                                                                                                                                                                                                                                       
    A = vector<lld>(K, 0);
    B = vector<lld>(K, 0);
    C = vector<lld>(K, 0);
    for(int i = 0, _a, _b, _c; i < K; i++){
        cin >> _a >> _b >> _c;
        A[i] = _a;
        B[i] = _b;
        C[i] = _c;
    }

    lld st = 1, en = N, mid;
    // for(lld i = st; i <= en; i++){ cout << i << " : "; cout << (func(i) ? 1 : 0) << "\n"; } cout << "\n";
    while(st <= en){
        mid = (st + en)/2;
        if(func(mid)){
            en = mid - 1;
        }else{
            st = mid + 1;
        }
    }
    cout << st << "\n";
    return 0;
}