#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define lld long long int

lld N, C, ans;
vector<lld> x;

bool func(int interval){
    auto last_router = x.begin();
    lld install_router = 1;

    for(auto iter = x.begin() + 1; iter != x.end(); iter++){
        if(*iter - *last_router >= interval){
            last_router = iter;
            install_router++;
        }
    }
    return install_router >= C;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> C;
    for(lld i = 0, tmp; i < N; i++){
        cin >> tmp;
        x.push_back(tmp);
    }
    sort(x.begin(), x.end());

    lld st = 1, en = x.back() - x.front() + 1, mid;

    while(st <= en){
        mid = (st + en)/2;
        if(func(mid)){
            ans = max(ans, mid);
            st = mid + 1;
        }else{
            en = mid - 1;
        }
    }
    cout << ans << "\n";
    return 0;
}