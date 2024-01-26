#include <bits/stdc++.h>
using namespace std;
#define lld long long int
lld N, bs[20], ans = INT64_MAX, bs_row_flip[20];
bool is_row_flip[20];


lld calculate_bitset(){
    lld val = 0;

    for(lld j = 0; j < N; j++){
        lld tmp = 0;
        for(lld i = 0; i < N; i++){
            if(is_row_flip[i]){
                if(bs_row_flip[i] & (1ll << j)) tmp++;
            }else{
                if(bs[i] & (1ll << j)) tmp++;
            }
        }
        val += min(tmp, N - tmp);
    }
    return val;
}

void func(lld d){

    if(d == N) return;

    ans = min(ans, calculate_bitset());

    is_row_flip[d] = false;
    func(d + 1);
    is_row_flip[d] = true;
    func(d + 1);

    return;
}

void print_bitset(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(is_row_flip[i]){
                if(bs_row_flip[i] & (1ll << j)) cout << "T";
                else cout << "H";
            }else{
                if(bs[i] & (1ll << j)) cout << "T";
                else cout << "H";
            }
        }
        cout << "\n";
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        for(int j = 0; j < N; j++){
            if(str[j] == 'T') bs[i] |= 1ll << j;
        }
        bs_row_flip[i] = ~bs[i];
    }
    func(0);
    cout << ans << "\n";
    return 0;
}