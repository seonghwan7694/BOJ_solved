#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;
bool flag = false;
int vis[3030][3030];
int N, M, K;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(){
    int ret = 0;
    queue<pair<int, int>> q;
    q.push({1, 1});
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for(int d = 0; d < 4; d++){
            int nx = x + dx[d], ny = y + dy[d];
            if(nx < 1 or nx > N or ny < 1 or ny > M) continue;
            if(vis[nx][ny] == -1 or vis[nx][ny] != 0) continue;
            vis[nx][ny] = vis[x][y] + 1;
            q.push({nx, ny});
        }
    }
    if(vis[N][M] != 0){
        cout << "YES" << "\n";
        cout << vis[N][M] << "\n";
    }else{
        cout << "NO" << "\n";
    }
    return;
}

void func(int x, int y, int c){
    int nx, ny;

    // 1
    nx = x - c, ny = y;
    for(int i = 0; i <= c; i++, nx++, ny++){
        if(nx < 1 or nx > N or ny < 1 or ny > M) continue;
        vis[nx][ny] = -1;
    }
    // 2
    nx = x, ny = y + c;
    for(int i = 0; i <= c; i++, nx++, ny--){
        if(nx < 1 or nx > N or ny < 1 or ny > M) continue;
        vis[nx][ny] = -1;
    }
    // 3
    nx = x + c, ny = y;
    for(int i = 0; i <= c; i++, nx--, ny--){
        if(nx < 1 or nx > N or ny < 1 or ny > M) continue;
        vis[nx][ny] = -1;
    }
    // 4
    nx = x, ny = y - c;
    for(int i = 0; i <= c; i++, nx--, ny++){
        if(nx < 1 or nx > N or ny < 1 or ny > M) continue;
        vis[nx][ny] = -1;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> M >> K;
    for(int i = 0, r, c, d; i < K; i++){
        cin >> r >> c >> d;
        func(r, c, d);
    }
    bfs();
    // for(int i = 1; i <= N; i++){ for(int j = 1; j <= M; j++){ cout << vis[i][j] << " "; } cout << "\n"; }
    return 0;
}