#include <bits/stdc++.h>
using namespace std;
#define lld long long int
lld N, K;
vector<lld> v[4];
vector<lld> num;
lld A0, B0, C0, D0;

pair<char, lld> func(char c1, lld u1, char c2, lld u2){
    if(c1 == 'A' and c2 == 'B'){ // b, a
        if(u1 * num[1] > u2 * num[0]) return {c1, u1};
        if(u1 * num[1] < u2 * num[0]) return {c2, u2};
    }else if(c1 == 'C' and c2 == 'D'){ // d, c
        if(u1 * num[3] > u2 * num[2]) return {c1, u1};
        if(u1 * num[3] < u2 * num[2]) return {c2, u2};
    }else if(c1 == 'A' and c2 == 'C'){ // c, a
        if(u1 * num[2] > u2 * num[0]) return {c1, u1};
        if(u1 * num[2] < u2 * num[0]) return {c2, u2};
    }else if(c1 == 'A' and c2 == 'D'){ // d, a
        if(u1 * num[3] > u2 * num[0]) return {c1, u1};
        if(u1 * num[3] < u2 * num[0]) return {c2, u2};
    }else if(c1 == 'B' and c2 == 'C'){ // c, b
        if(u1 * num[2] > u2 * num[1]) return {c1, u1};
        if(u1 * num[2] < u2 * num[1]) return {c2, u2};
    }else if(c1 == 'B' and c2 == 'D'){ // d, b
        if(u1 * num[3] > u2 * num[1]) return {c1, u1};
        if(u1 * num[3] < u2 * num[1]) return {c2, u2};
    }
    return {c1, u1};
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> K;
    for(lld i = 0, tmp; i < 4; i++){
        cin >> tmp;
        num.push_back(tmp);
    }
    for(lld i = 0; i < N; i++){
        char t; lld u;
        cin >> t >> u;
        v[t - 'A'].push_back(u);
    }
    for(lld i = 0; i < 4; i++){
        v[i].push_back(0);
        sort(v[i].begin(), v[i].end(), less<lld>());
    }

    while(K--){
        auto val1 = func('A', v[0].back(), 'B', v[1].back());
        auto val2 = func('C', v[2].back(), 'D', v[3].back());
        auto ans = func(val1.first, val1.second, val2.first, val2.second);

        num[ans.first - 'A'] += ans.second;
        cout << ans.first << " " << ans.second << "\n";
        v[ans.first - 'A'].pop_back();
    }


    return 0;
}