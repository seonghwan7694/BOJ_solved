#include <bits/stdc++.h>
using namespace std;
#define lld long long int
#define WALL '#' - '0'
lld N, M, P;
lld S[10];
lld MAP[1010][1010];
lld ans[11];
lld dx[4] = {-1, 1, 0, 0};
lld dy[4] = {0, 0, -1, 1};
vector<pair<lld, lld>> BOARDER[10];

void SET_BOARDER(){
    bool vis[1010][1010];
    memset(vis, false, sizeof vis);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(MAP[i][j] != 0 and !vis[i][j]){
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = true;


                while(!q.empty()){
                    auto cur = q.front();
                    q.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx < 0 or nx >= N or ny < 0 or ny >= M) continue;
                        if(!vis[nx][ny] and MAP[i][j] == MAP[nx][ny]){
                            vis[nx][ny] = true; 
                            q.push({nx, ny});
                        }
                        if(MAP[nx][ny] == 0) BOARDER[MAP[i][j]].push_back({nx, ny});
                    }
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> M >> P;
    for(int i = 1; i <= P; i++){
        cin >> S[i];
    }
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        for(int j = 0; j < M; j++){
            if(str[j] != '.') MAP[i][j] = str[j] - '0';
            if(str[j] == '#') MAP[i][j] = -1;
        }
    }

    SET_BOARDER();

    bool flag = false;
    while(true){
        for(int i = 1; i <= P; i++){
            queue<pair<int, int>> q;
            for(auto &x : BOARDER[i]){
                if(MAP[x.first][x.second] == 0){
                    MAP[x.first][x.second] = i;
                    q.push(x);
                    flag = true;
                }
            }
            BOARDER[i].clear();

            for(lld s = 1; s <= S[i]; s++){
                lld Q_SIZE = q.size();
                if(Q_SIZE == 0) break;
                for(int j = 0; j < Q_SIZE; j++){
                    auto cur = q.front();
                    q.pop();

                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];
                        if(nx < 0 or nx >= N or ny < 0 or ny >= M) continue;
                        if(MAP[nx][ny] == 0){
                            if(s == S[i]) BOARDER[i].push_back({nx, ny});
                            else{
                                MAP[nx][ny] = i;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
        if(!flag) break;
        else flag = false;
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(MAP[i][j] != -1) ans[MAP[i][j]]++;
        }
    }
    for(int i = 1; i <= P; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
    // for(int i = 0; i < N; i++){ for(int j = 0; j < M; j++){ cout << MAP[i][j]; } cout << "\n"; }
    return 0;
}