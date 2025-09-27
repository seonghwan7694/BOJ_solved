#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX_SIZE 101010
ll N, ans;
vector<ll> h(MAX_SIZE), R(MAX_SIZE), L(MAX_SIZE);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(ll i = 0, tmp; i < N; i++){
        cin >> h[i];
    }
    stack<ll> s;
    s.push(0);
    for(int i = N - 1; i >= 0; i--){
        while(!s.empty() and h[i] <= h[s.top()])  s.pop();
        R[i] = (s.empty() ? i : s.top());
        s.push(i);
    }

    while(!s.empty()) s.pop();
    s.push(N - 1);
    while(!s.empty()) s.pop();
    for(int i = 0; i < N; i++){
        while(!s.empty() and h[i] <= h[s.top()]) s.pop();
        L[i] = (s.empty() ? i : s.top());
        s.push(i);
    }
    for(int i = 0; i < N; i++){
        ans = max(ans, h[i] * (R[i] - L[i] - 1));
    }
    cout << ans << "\n";
    return 0;
}