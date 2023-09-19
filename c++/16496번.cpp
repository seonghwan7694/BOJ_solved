#include <bits/stdc++.h>
using namespace std;
#define lld long long int
lld N, cnt;
vector<string> v;
int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    
    for(int i = 0, tmp; i < N; i++){
        cin >> tmp;
        v.push_back(to_string(tmp));
        if(tmp == 0) cnt++;
    }
    if(cnt == N){
        cout << 0 << "\n";
        return 0;
    }
    sort(v.begin(), v.end(), [](string &a, string &b){
        if(a == "0") return false;
        if(b == "0") return true;
        return a + b > b + a;
    });
    for(auto &x : v) cout << x;
    cout << "\n";
    return 0;
}