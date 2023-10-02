#include <bits/stdc++.h>
using namespace std;

int N, M;
map<string, set<string>> m;
map<string, string> mm;

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        string team_name, member;
        int cnt;
        cin >> team_name;
        cin >> cnt;
        for(int j = 0; j < cnt; j++){
            cin >> member;
            m[team_name].insert(member);
            mm[member] = team_name;
        }
    }
    while(M--){
        string str;
        int cmd;
        cin >> str >> cmd;

        if(cmd == 0){
            for(auto &x : m[str]) cout << x << "\n";
        }else{
            cout << mm[str] << "\n";
        }
    }


    return 0;
}