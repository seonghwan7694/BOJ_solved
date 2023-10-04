#include <bits/stdc++.h>
using namespace std;

pair<int, int> graph[101010];
long long int N, edge;
long long int ans, END_NODE;
bool END = false;
vector<int> v;

void FIND_END_NODE(int root){
    int &lc = graph[root].first;
    int &rc = graph[root].second;
    if(lc != -1){
        FIND_END_NODE(lc);
    }
    v.push_back(root);
    if(rc != -1){
        FIND_END_NODE(rc);
    }
    return;
}

bool vis[101010];
int parent[101010];
void func(int cur_node){
    if(END) return;
    int &lc = graph[cur_node].first;
    int &rc = graph[cur_node].second;

    if(lc != -1 and !vis[lc]){
        ans++;
        vis[lc] = true;
        func(lc);
    }else if(rc != -1 and !vis[rc]){
        ans++;
        vis[rc] = true;
        func(rc);
    }else if(cur_node == END_NODE){
        END = true;
        return;
    }else if(parent[cur_node] != -1){
        ans++;
        func(parent[cur_node]);
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0, lc, rc, r; i < N; i++){
        cin >> r >> lc >> rc;
        graph[r] = {lc, rc};
        parent[lc] = r;
        parent[rc] = r;
    }
    FIND_END_NODE(1);
    END_NODE = v.back();
    func(1);
    cout << ans << "\n";
    return 0;
}