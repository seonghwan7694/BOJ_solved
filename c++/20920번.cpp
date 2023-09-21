#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define lld long long int

unordered_map<string, lld> um;
int main(){
    ios::sync_with_stdio(false);
    lld N, M;
    cin >> N >> M;
    for(lld i = 0; i < N; i++){
        string str;
        cin >> str;
        if(str.length() < M) continue;
        um[str]++;
    }
    vector<pair<string, lld>> v(um.begin(), um.end());
    sort(v.begin(), v.end(), [](pair<string, lld> &a, pair<string, lld> &b){
        if(a.second == b.second){
            if(a.first.length() == b.first.length()){
                return a.first < b.first;
            }
            return a.first.length() > b.first.length();
        }
        return a.second > b.second;
    });
    for(auto &x : v) cout << x.first << "\n";
    return 0;
}