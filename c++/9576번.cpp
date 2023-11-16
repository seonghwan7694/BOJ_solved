#include <bits/stdc++.h>
using namespace std;

int T, N, M;
vector<bool> visited;
vector<int> partner;
vector<pair<int, int>> v;
int adj[1010][1010];

bool dfs(int here) {
	if (visited[here]) return false;
	visited[here] = true;
	for (int there = v[here].first; there <= v[here].second; there++) {
		if (adj[here][there]) {
			if (partner[there] == -1 || dfs(partner[there])) {
				partner[there] = here;
				return true;
			}
		}
	}
	return false;
}

int bipartiteMatch() {
	int ret = 0;
	for (int i = 0; i < M; i++) {
		visited = vector<bool>(M + 1, false);
		if (dfs(i)) ret++;
	}
	return ret;
}

void solve(){
    v.clear();
    partner = vector<int>(1010, -1);
    cin >> N >> M;
    for(int i = 0, a, b; i < M; i++){
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b){ 
        return a.second < b.second;
    });
    for(int i = 0; i < M; i++){
        int a = v[i].first;
        int b = v[i].second;
        for(int j = a; j <= b; j++) adj[i][j] = 1;
    }
    cout << bipartiteMatch() << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--) solve();
    return 0;
}