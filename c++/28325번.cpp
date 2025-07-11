#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
#define ll long long

ll N, ans, C;
bool nxt = true;
deque<ll> dq;

int main(){
    ios::sync_with_stdio(false);
    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> C;
        dq.push_back(C);
    }
    ll dq_MAX = *max_element(dq.begin(), dq.end());
    while(dq.front() != dq_MAX){
        ll tmp = dq.front();
        dq.pop_front();
        dq.push_back(tmp);
    }
    for(auto iter = dq.begin(); iter != dq.end(); iter++){
        
    }
    cout << ans << "\n";
    return 0;
}