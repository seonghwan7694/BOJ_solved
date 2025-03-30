#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int ret = 0;
    vector<char> ch;
    for(auto c : s) ch.push_back(c);
    sort(ch.begin(), ch.end());
    s.clear();
    for(auto c : ch) s.push_back(c);

    do{
        bool flag = false;
        for(int i = 0; i < s.length() - 1; i++){
            if(s[i] == s[i + 1]){
                flag = true;
                break;
            }
        }
        if(flag) continue;
        ret++;
    }while(next_permutation(s.begin(), s.end()));
    cout << ret << "\n";
    return 0;
}