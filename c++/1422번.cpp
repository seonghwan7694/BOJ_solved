#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <string>
using namespace std;
#define lld unsigned long long int
lld N, K;
vector<lld> v;
vector<string> v_str;
string str, big_str;

int main(){
    ios::sync_with_stdio(false);
    cin >> K >> N;
    for(int i = 0, tmp; i < K; i++){
        cin >> tmp;
        v.push_back(tmp);
        v_str.push_back(to_string(tmp));
    }
    big_str = to_string(*max_element(v.begin(), v.end()));
    for(int i = 0; i < N - K; i++){
        v_str.push_back(big_str);
    }
    sort(v_str.begin(), v_str.end(), [](string &A, string &B){
        return A + B > B + A;
    });
    for(auto &x : v_str) cout << x;
    cout << "\n";
    return 0;
}