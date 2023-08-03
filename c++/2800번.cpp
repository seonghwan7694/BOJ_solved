#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

vector<pair<int, int>> v;
set<string> vv;
string str;
bool chk[202];

void func(int idx){
    if(idx == v.size()){
        string s;
        for(int i = 0; i < str.length(); i++){
            if(chk[i]) continue;
            s += str[i];
        }
        vv.insert(s);
        return;
    }
    for(int i = idx; i < v.size(); i++){
        auto [a, b] = v[i];
        func(idx + 1);
        chk[a] = chk[b] = true;
        func(idx + 1);
        chk[a] = chk[b] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    stack<int> s;
    cin >> str;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == ')'){
            v.push_back({s.top(), i});
            s.pop();
        }else if(str[i] == '('){
            s.push(i);
        }
    }
    func(0);
    vector<string> vvv(vv.begin(), vv.end());
    sort(vvv.begin(), vvv.end());
    vvv.erase(unique(vvv.begin(), vvv.end()), vvv.end());
    for(auto x : vvv){
        if(x != str) cout << x << "\n";
    }
    return 0;
}