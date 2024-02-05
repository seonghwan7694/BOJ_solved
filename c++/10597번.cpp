#include <bits/stdc++.h>
#include <string>
using namespace std;

string str;
vector<int> v;
bool num[1111];
bool stop = false;

void func(int pos, int n){

    if(pos + n > str.length()){
        for(int i = 1; i <= v.size(); i++){
            if(num[i]) continue;
            return;
        }
        for(auto &x : v) cout << x << " ";
        cout << "\n";
        exit(0);
    }

    string tmp(str.begin() + pos, str.begin() + pos + n);
    int m = stoi(tmp);
    if(m == 0 or m > 50) return;
    // cout << "pos : " << pos << ", " << "n : " << n << ", " << m << "\n";

    if(num[m] == false){
        num[m] = true;
        v.push_back(m);
        func(pos + n, 1);
        v.pop_back();
        num[m] = false;
    }
    func(pos, n + 1);
    
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> str;
    func(0, 1);
    return 0;
}