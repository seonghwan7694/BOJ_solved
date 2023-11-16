#include <bits/stdc++.h>
using namespace std;
#define lld long long int

lld N, M, L, ans;
vector<lld> v;

bool func(lld mid){
	lld cnt = 0;
	for(int i=1; i<v.size(); i++){
		lld dist = v[i] - v[i-1];
		cnt += dist / mid;
		if(dist % mid == 0){
			cnt--;
		}
	}
	return cnt > M;
}

int main(){
    ios::sync_with_stdio(false);

    cin >> N >> M >> L;
    for(lld i = 0, tmp; i < N; i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    v.push_back(0);
    v.push_back(L);
    sort(v.begin(), v.end());

    lld st = 1, en = L, mid;

    while(st <= en){
        mid = (st + en)/2;
        if(func(mid)){
            st = mid + 1;
        }else{
            ans = mid;
            en = mid - 1;
        }
    }
    cout << ans << "\n";
    return 0;
}