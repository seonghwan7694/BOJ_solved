#include <bits/stdc++.h>
using namespace std;

int N, M, ret[101];
vector<int> g[101];
bool visited[101];

void func(int s){
    queue<pair<int, int>> q;
    fill(visited, visited + 101, false);
    q.push({s, 0});
    visited[s] = true;
    while(!q.empty()){
        auto [u, w] = q.front();
        q.pop();
        for(auto v : g[u]){
            if(!visited[v]){
                ret[s] += w + 1;
                q.push({v, w + 1});
                visited[v] = true;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0, u, v; i < M; i++){
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 1; i <= N; i++){
        func(i);
    }
    int MIN_VALUE = *min_element(ret + 1, ret + 1 + N);
    for(int i = 1; i <= N; i++) if(MIN_VALUE == ret[i]){
        cout << i << "\n";
        break;
    }
    return 0;
}