#include <bits/stdc++.h>
#include <queue>
using namespace std;

int N, L, P, ans; // L : distance from init to village, P : init fuel
vector<pair<int, int>> gas_station;
priority_queue<int> pq;

int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    for(int n = 0, loc, fuel; n < N; n++){
        cin >> loc >> fuel;
        gas_station.push_back({loc, fuel});
    }
    cin >> L >> P;
    gas_station.push_back({L, 0});
    sort(gas_station.begin(), gas_station.end());

    for(int n = 0; n <= N; n++){
        while(gas_station[n].first > P){
            if(pq.empty()){
                cout << -1 << "\n";
                return 0;
            }
            P += pq.top();
            pq.pop();
            ans++;
        }
        pq.push(gas_station[n].second);
    }
    cout << ans << "\n";
    return 0;
}