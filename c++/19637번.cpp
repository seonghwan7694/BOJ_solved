#include <bits/stdc++.h>
using namespace std;
#define lld int
lld N, M;
vector<lld> v;
string s[100001];

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(lld i = 0, idx = 0, val = 0, o_val = -1; i < N; i++){
        string str;
        cin >> str >> val;
        if(val == o_val) continue;
        o_val = val;
        v.push_back(val);
        s[idx++] = str;
        cin.clear();
    }
    
    queue<int> q;
    for(int i = 0, val; i < M; i++){
        cin >> val;
        q.push(val);
    }
    for(int i = 0, val; i < M; i++){
        val = q.front();
        q.pop();
        cout << s[lower_bound(v.begin(), v.end(), val) - v.begin()] << '\n';
    }
    return 0;
}