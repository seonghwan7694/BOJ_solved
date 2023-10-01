#include <bits/stdc++.h>
using namespace std;

int N, M;
map<int,multiset<pair<int,int>>> group;
multiset<pair<int,int>> level;
map<int,pair<int,int>> find_value_map;

void query(string str){
    int a, b, c;
    if(str == "recommend"){
        cin >> a >> b;
        if(b == 1) cout << prev(group[a].end())->second << "\n";
        if(b == -1) cout << group[a].begin()->second << "\n";
    }else if(str == "recommend2"){
        cin >> a;
        if(a == 1) cout << prev(level.end())->second << "\n";
        if(a == -1) cout << level.begin()->second << "\n";
    }else if(str == "recommend3"){
        cin >> a >> b;
        if(a == 1){
            auto it = level.lower_bound({b,-1e9});
            if(it != level.end()) cout << it->second << '\n';
            else cout << -1 << '\n';
        }else if(a == -1){
            auto it = level.upper_bound({b,-1e9});
            if(it != level.begin()) cout << (--it)->second << '\n';
            else cout << -1 << '\n';
        }
    }else if(str == "add"){
        int p,l,g;
        cin >> p >> l >> g;
        group[g].insert({l,p});
        level.insert({l,p});
        find_value_map[p] = {l,g};
    }else{
        int p;
        cin >> p;
        int l = find_value_map[p].first;
        int g = find_value_map[p].second;
        group[g].erase({l,p});
        level.erase({l,p});
        find_value_map.erase(p);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0, p, l, g; i < N; i++){
        cin >> p >> l >> g;
        group[g].insert({l, p});
        level.insert({l, p});
        find_value_map[p] = {l, g};
    }
    cin >> M;
    while(M--){
        string str;
        cin >> str;
        query(str);
    }

    return 0;
}