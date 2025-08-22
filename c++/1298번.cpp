#include <iostream>
#include <vector>
using namespace std;

int N, M, ret;
vector<int> g[101];
int A[101], B[5001];
bool visited[101];

bool dfs(int a){
    visited[a] = true;

    for(int b : g[a]){
        if(B[b] == -1 or !visited[B[b]] and dfs(B[b])){
            A[a] = b;
            B[b] = a;
            return true;
        }
    }

    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    fill(A, A + 101, -1);
    fill(B, B + 5001, -1);
    for(int i = 0, a, b; i < M; i++){
        cin >> a >> b;
        g[a].push_back(b);
    }
    for(int a = 1; a <= N; a++){
        fill(visited, visited + 101, false);
        if(dfs(a)) ret++;
    }

    cout << ret << "\n";
    return 0;
}