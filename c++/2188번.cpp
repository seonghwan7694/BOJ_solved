#include <bits/stdc++.h>
using namespace std;

int N, M;
int adj[202][202];
vector<bool> visited;
vector<int> partner(202, -1);

bool dfs(int here) {
	if (visited[here]) return false;
	visited[here] = true;
	for (int there = 1; there <= M; there++) {
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
	for (int i = 1; i <= N; i++) {
		visited = vector<bool>(N + 1, false);
		if (dfs(i)) ret++;
	}
	return ret;
}


int main(){
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 1, T, tmp; i <= N; i++){
        cin >> T;
        while(T--){
            cin >> tmp;
            adj[i][tmp] = 1;
        }
    }
    cout << bipartiteMatch() << "\n";
    return 0;
}