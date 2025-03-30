#include <bits/stdc++.h>
using namespace std;

int R, C;
vector<vector<int>> score(505, vector<int>(505, 0));
vector<vector<int>> board(505, vector<int>(505, 0));
bool visited[505][505];
int dx[8] = {-1, 1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int parent[505 * 505];

int Find(int u){
    if(u == parent[u]){
        return u;
    }
    return parent[u] = Find(parent[u]);
}

void Merge(int u, int v){
    u = Find(u);
    v = Find(v);
    if(u == v) return;
    // Merge v -> u
    parent[v] = u;
}

void Liquid(pair<int, int> prev){
    int min_dir = -1, min_val = board[prev.first][prev.second];
    for(int dir = 0; dir < 8; dir++){
        int nx = prev.first + dx[dir];
        int ny = prev.second + dy[dir];

        if(0 <= nx and nx < R and 0 <= ny and ny < C){
            if(board[nx][ny] < min_val){
                min_val = board[nx][ny];
                min_dir = dir;
            }
        }
    }

    if(min_dir == -1) return;

    pair<int, int> next = {prev.first + dx[min_dir], prev.second + dy[min_dir]};
    if (!visited[next.first][next.second]) {
        visited[next.first][next.second] = true;
        Liquid(next);
    }
    Merge(next.first * C + next.second, prev.first * C + prev.second);
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++) cin >> board[i][j];
    }
    for(int i = 0; i < 505 * 505; i++) parent[i] = i;

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++) if(!visited[i][j]) visited[i][j] = true, Liquid({i, j});
    }

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            int p = Find(i * C + j);
            int x = p / C;
            int y = p % C;
            score[x][y]++;
        }
    }

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout << score[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}