#include <bits/stdc++.h>
using namespace std;

int N, M;
map<int, int> kte, etk;
vector<int> e[1010];

void solve(int st){
    vector<int> ans;
    queue<int> q;

    ans.push_back(etk[st]);
    q.push(st);

    while(!q.empty()){
        auto &cur = q.front();
        q.pop();
        for(auto &nxt : e[cur]){
            ans.push_back(etk[nxt]);
            q.push(nxt);
        }
    }
    reverse(ans.begin(), ans.end());
    if(ans.size() == N){
        for(auto &x : ans) cout << x << " ";
        cout << "\n";
    }

    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> M;
    vector<int> idx(N + 1), cnt(N + 1);
    iota(idx.begin(), idx.end(), 0);
    fill(cnt.begin(), cnt.end(), 0);

    int A[M], c = 1;
    for(int i = 0; i < N - M + 1; i++){
        for(int j = 0; j < M; j++){
            cin >> A[j];
            if(kte.find(A[j]) == kte.end()){
                kte.insert({A[j], c});
                etk.insert({c, A[j]});
                c++;
            }
            cnt[kte[A[j]]]++;
            if(j != 0 and e[c].empty()) e[kte[A[j]]].push_back(kte[A[j-1]]);
        }
    }

    vector<int> v;
    for(int i = 0; i <= N; i++){
        if(cnt[i] == 1) v.push_back(i);
    }

    for(auto x : v) solve(x);

    return 0;
}