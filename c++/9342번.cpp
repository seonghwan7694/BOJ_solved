#include <bits/stdc++.h>
#include <regex>
using namespace std;
int N;
string str;

int main(){
    ios::sync_with_stdio(false);
    regex re("^([A-F]{0,1})(A)+(?=.*F)(F)+(?=.*C)(C)+([A-F]{0,1})$");
    cin >> N;
    while(N--){
        cin >> str;
        if(regex_match(str, re)) cout << "Infected!" << "\n";
        else cout << "Good" << "\n";
    }

    return 0;
}