#include <bits/stdc++.h>
using namespace std;
#define lld long long int

lld N, M;
vector<lld> v;

lld func(int limit){
    lld val = 0;
    for(auto &x : v){
        val += (x >= limit ? limit : x);
    }
    return val;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    for(lld i = 0, tmp; i < N; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    cin >> M;
    sort(v.begin(), v.end());

    lld st = 1, en = v.back(), mid, ans = 0;

    while(st <= en){
        mid = (st + en)/2;
        if(func(mid) > M){
            en = mid - 1;
        }else{
            ans = max(ans, mid);
            st = mid + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}