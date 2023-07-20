#include <bits/stdc++.h>
using namespace std;
int N;
vector<pair<int, int>> v;
vector<int> ROW[10101];
int COL[10101];
int node_num = 1;
int ROOT = -1;

void dfs(int root_node, int depth){
    int leftSubTree = v[root_node].first;
    int rightSubTree = v[root_node].second;
    if(leftSubTree != -1) dfs(leftSubTree, depth + 1);
    ROW[depth].push_back(root_node);
    COL[root_node] = node_num++;
    if(rightSubTree != -1) dfs(rightSubTree, depth + 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    v.resize(N + 1);
    for(int i = 0, rootNode, leftNode, rightNode; i < N; i++){
        cin >> rootNode >> leftNode >> rightNode;
        v[rootNode] = make_pair(leftNode, rightNode);
    }
    for(int r = 1; r <= N; r++){
        int node_cnt = 1;
        if(ROOT != -1) break;
        queue<int> q;
        q.push(r);
        while(!q.empty()){
            int leftNode = v[q.front()].first;
            int rightNode = v[q.front()].second;
            q.pop();
            if(leftNode != -1) q.push(leftNode), node_cnt++;
            if(rightNode != -1) q.push(rightNode), node_cnt++;
            if(node_cnt == N){
                ROOT = r;
                break;
            }
        }
    }

    dfs(ROOT, 1);
    int a1 = -1, a2 = -1;
    for(int i = 1; i <= 10100; i++){
        if(ROW[i].empty()) break;
        if(a2 < COL[ROW[i].back()] - COL[ROW[i].front()] + 1){
            a1 = i;
            a2 = COL[ROW[i].back()] - COL[ROW[i].front()] + 1;
        }
    }
    cout << a1 << " " << a2 << "\n";
    return 0;
}