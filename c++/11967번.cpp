#include <bits/stdc++.h>
using namespace std;

int N, M;
bool MAP[101][101];
bool LIGHT[101][101];
vector<pair<int, int>> SWITCH[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool CAN_GO(int &x, int &y){
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 1 or nx > N or ny < 1 or ny > N) continue;
        if(MAP[nx][ny] == 1) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0, x, y, a, b; i < M; i++){
        cin >> x >> y >> a >> b;
        SWITCH[x][y].push_back({a, b});
    }
    
    queue<pair<int, int>> q;
    q.push({1, 1});
    MAP[1][1] = true;
    LIGHT[1][1] = true;

    while(!q.empty()){
        auto cur = q.front();
        vector<pair<int, int>> LIGHT_ON;
        q.pop();

        for(auto &x : SWITCH[cur.first][cur.second]){
            if(!LIGHT[x.first][x.second]){
                LIGHT[x.first][x.second] = true;
                LIGHT_ON.push_back({x.first, x.second});
            }
        }
        for(int i = 0; i < 4; i++){ int nx = cur.first + dx[i]; int ny = cur.second + dy[i]; if(nx < 1 or nx > N or ny < 1 or ny > N) continue; if(LIGHT[nx][ny] && !MAP[nx][ny]){ MAP[nx][ny] = 1; q.push({nx, ny}); } }
        for(auto &x : LIGHT_ON){
            if(!MAP[x.first][x.second] and CAN_GO(x.first, x.second)){
                    MAP[x.first][x.second] = true;
                    q.push({x.first, x.second});
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= N; i++){ 
        for(int j = 1; j <= N; j++){
            if(LIGHT[i][j]) ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}