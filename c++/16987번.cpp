#include <bits/stdc++.h>
using namespace std;

int N, res;
vector<pair<int, int>> v;

void func(int idx){
    if(idx >= N){
        int tmp = 0;
        for(int i = 0; i < N; i++){
            if(v[i].first <= 0) tmp++;
        }
        res = max(res, tmp);
        return;
    }

    if(v[idx].first <= 0){
        func(idx + 1);
        return;
    }


    bool flag = false;
    for(int i = 0; i < N; i++){
        if(i == idx or v[i].first <= 0) continue;

        v[i].first -= v[idx].second;
        v[idx].first -= v[i].second;

        flag = true;
        func(idx + 1);

        v[i].first += v[idx].second;
        
        v[idx].first += v[i].second;

    }
    if(!flag) func(N);
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0, s, w; i < N; i++){ // s : 내구도
        cin >> s >> w;
        v.push_back({s, w});
    }
    func(0);
    cout << res << "\n";
    return 0;
}