#include <bits/stdc++.h>
using namespace std;
#define lld long long int

vector<pair<lld, lld>> v[101];
lld in[101], cnt[101];
int N, M;

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0, X, Y, K; i < M; i++){
        cin >> X >> Y >> K;
        v[X].push_back({Y, K});
        in[Y]++;
    }
    vector<lld> ans;
    queue<lld> q;
    q.push(N);
    cnt[N] = 1;
    while(!q.empty()){
        lld cur = q.front(); q.pop();
        if(v[cur].empty()){
            ans.push_back(cur);
        }
        for(auto &x : v[cur]){
            lld &nxt = x.first;
            lld &c = x.second;
            cnt[nxt] += cnt[cur] * c;
            if(--in[nxt] == 0) q.push(nxt);
        }
    }
    sort(ans.begin(), ans.end());
    for(auto x : ans) cout << x << " " << cnt[x] << "\n";
    return 0;
}