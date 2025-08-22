#include <iostream>
#include <vector>

using namespace std;
int N, M, ANS;
vector<int> g[1001];

int A[1001], B[1001];
bool visited[1001];

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
    for(int u = 1, k, v; u <= N; u++){
        cin >> k;
        while(k--){
            cin >> v;
            g[u].push_back(v);
        }
    }
    fill(A, A + 1001, -1);
    fill(B, B + 1001, -1);
    for(int a = 1; a <= N; a++){
        if(A[a] == -1){
            fill(visited, visited + 1001, false);
            if(dfs(a)) ANS++;
        }
    }
    cout << ANS << "\n";
    return 0;
}