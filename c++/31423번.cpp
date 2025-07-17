#include <vector>
#include <iostream>
#include <string>
#define pii pair<int, int>
using namespace std;
int N;
vector<string> s;
vector<pii> p;
vector<int> adj[500'001];
bool vis[500'001];

void dfs(int n){
    vis[n] = true;
    cout << s[n];
    for(auto x : adj[n]){
        if(vis[x]) continue;
        vis[n] = true;
        dfs(x);
    }
    return;
}   
int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    s = vector<string>(N + 1);
    for(int i = 1; i <= N; i++) cin >> s[i];
    for(int i = 0, x, y; i < N - 1; i++){
        cin >> x >> y;
        p.push_back({x, y});
        adj[x].push_back(y);
    }
    dfs(p.back().first);
    cout << "\n";
    return 0;
}