#include <iostream>
#include <vector>
int N, M, ret;
using namespace std;
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
    fill(A, A + 1001, -1);
    fill(B, B + 1001, -1);
    for(int a = 1, b, k; a <= N; a++){
        cin >> k;
        while(k--){
            cin >> b;
            g[a].push_back(b);
        }
    }

    for(int a = 1; a <= N; a++){
        for(int c = 0; c < 2; c++){
            fill(visited, visited + 1001, false);
            if(dfs(a)) ret++;
        }
    }
    cout << ret << "\n";
}