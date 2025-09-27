#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> v(N), ans(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    stack<int> s;
    for(int i = N - 1; i >= 0; i--){
        while(!s.empty() and v[i] >= s.top()) s.pop();
        ans[i] = (s.empty() ? -1 : s.top()); 
        s.push(v[i]);
    }
    for(auto x : ans) cout << x << " ";
    cout << "\n";
    return 0;
}