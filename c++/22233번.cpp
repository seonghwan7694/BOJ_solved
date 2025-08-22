#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
using namespace std;
int N, M;
string str;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    unordered_set<string> s;
    while(N--){
        cin >> str;
        s.insert(str);
    }
    while(M--){
        cin >> str;
        string token;
        stringstream ss(str);

        while(getline(ss, token, ',')){
            s.erase(token);
        }
        cout << s.size() << "\n";
    }

    return 0;
}
