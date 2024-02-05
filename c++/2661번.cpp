#include <bits/stdc++.h>
#include <string>
using namespace std;

int N;
string val;

bool is_valid(){
    for(int len = 1; len <= val.length()/2; len++){
        for(int pos = 0; pos + 2 * len <= val.length(); pos++){
            string tmp1(val.begin() + pos, val.begin() + pos + len); // [pos, pos + len)
            string tmp2(val.begin() + pos + len, val.begin() + pos + 2 * len); // [pos + len, pos + 2*len)
            if(tmp1 == tmp2) return false;
        }
    }
    return true;
}

bool opti_is_valid(){
    for(int len = 1; len < val.length(); len++){
        for(int pos = val.length(); pos >= 0; pos--){
            string tmp1(val.begin() + pos - len, val.begin() + pos); // [pos - len, pos);
            string tmp2(val.begin() + pos - 2 * len, val.begin() + pos - len); // [pos - 2 * len, pos - len);
            if(tmp1 == tmp2) return false;
        }
    }
    return true;
}

void func(int n){
    if(n == N){
        cout << val << "\n";
        exit(0);
    }

    for(int i = 1; i <= 3; i++){
        if(val.back() == i + '0') continue;
        val.push_back(i + '0');
        if(is_valid()){
            func(n + 1);
        }
        val.pop_back();
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    func(0);
    return 0;
}