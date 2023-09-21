#include <bits/stdc++.h>
using namespace std;

int N, Q;
vector<int> graph[101010];
int node_color[101010];
int parent_node[101010];
int ans[101010];

bool vis[101010];

void bfs(int node){
    memset(vis, 101010, false);
    queue<int> q;
    queue<int> n;
    set<int> s;

    vis[node] = true;
    s.insert(node_color[node]);
    q.push(node);
    n.push(node);

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(auto nxt : graph[cur]){
            if(!vis[nxt]){
                vis[nxt] = true;
                s.insert(node_color[nxt]);
                q.push(nxt);
                n.push(nxt);
            }
        }
    }
    while(!n.empty()){
        ans[q.front()] = s.size();
        q.pop();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> Q;
    for(int i = 1, tmp; i <= N - 1; i++){
        cin >> tmp;
        parent_node[i+1] = tmp;
        graph[tmp].push_back(i+1);
        graph[i+1].push_back(tmp);
    }
    for(int i = 1, c; i <= N; i++){
        cin >> c;
        node_color[i] = c;
    }
    int cnt = N + Q - 1;
    int cmd, node;
    while(cnt--){
        cin >> cmd >> node;
        if(cmd == 1){
            graph[node].erase(find(graph[node].begin(), graph[node].end(), parent_node[node]));
            graph[parent_node[node]].erase(find(graph[parent_node[node]].begin(), graph[parent_node[node]].end(), node));
            bfs(node);
            bfs(parent_node[node]);
        }else{
            cout << ans[node] << "\n";
        }
    }
    return 0;
}