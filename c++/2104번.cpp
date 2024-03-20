#include <bits/stdc++.h>
using namespace std;
#define SIZE 101010
#define ll long long
ll A[SIZE], N;

ll func(ll st, ll en){
    if(st == en) return A[st] * A[st];
    ll ret = -1;

    ll mid = (st + en)/2;
    ll res_left = func(st, mid);
    ret = max(ret, res_left);
    ll res_right = func(mid + 1, en);
    ret = max(ret, res_right);

    ll le = mid, ri = mid + 1;
    ll min_value = min(A[le], A[ri]);
    ll segment_sum = A[le] + A[ri];
    ret = max(ret, segment_sum * min_value);

    while((st < le) || (ri < en)){
        if(ri < en and (st == le or A[le - 1] < A[ri + 1])){
            segment_sum += A[++ri];
            min_value = min(min_value, A[ri]);
            ret = max(ret, segment_sum * min_value);
        }else{
            segment_sum += A[--le];
            min_value = min(min_value, A[le]);
            ret = max(ret, segment_sum * min_value);
        }
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }
    cout << func(1, N) << "\n";
    return 0;
}