#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
struct pair_hash {
    size_t operator()(const pii &p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

int T;
unordered_set<pii, pair_hash> s;

bool find_rectangle(pii &p1, pii &p2, pii &n){
    // p1 + n
    if(s.find({p1.first + n.first, p1.second + n.second}) == s.end()) return false;
    // p2 + n
    if(s.find({p2.first + n.first, p2.second + n.second}) == s.end()) return false;
    return true;
}

void solve(){
    int N, a, b, ret = 0;
    s.clear();
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        s.insert({a, b});
    }

    // 점 2개를 잡으면, 그릴 수 있는 정사각형이 결정됨
    vector<pii> v(s.begin(), s.end());
    for(int i = 0; i < v.size(); i++){
        for(int j = i + 1; j < v.size(); j++){
            pii &p1 = v[i];
            pii &p2 = v[j];

            int dx = p2.first - p1.first;
            int dy = p2.second - p1.second;
            if(dx*dx + dy*dy < ret) continue;

            pii n1 = {-dy, dx};
            pii n2 = {dy, -dx};
            
            if(find_rectangle(p1, p2, n1)){
                ret = max(ret, dx*dx + dy*dy);
            }
            if(find_rectangle(p1, p2, n2)){
                ret = max(ret, dx*dx + dy*dy);
            }
        }
    }

    cout << ret << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}