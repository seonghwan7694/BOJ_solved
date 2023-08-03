#include <bits/stdc++.h>
using namespace std;

string str;
int ans, tmp;

int main(){
    ios::sync_with_stdio(false);
    cin >> str;

    for(int i = 0; i < str.length(); i++){
        if(i + 1 < str.length() and str[i] == '(' and str[i + 1] == ')'){
            ans += tmp;
            i++;
            // cout << tmp << "\n";
        }else if(str[i] == '('){
            tmp++;
        }else if(str[i] == ')'){
            tmp--;
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}