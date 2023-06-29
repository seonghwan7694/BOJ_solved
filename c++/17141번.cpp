#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int MAP_SIZE, PUT_VIRUS, ans;
const int ERROR_ANS = 99999;
vector<tuple<int, int>> point_virus;

int main(){
    ios::sync_with_stdio(false);
    cin >> MAP_SIZE >> PUT_VIRUS;
    vector<vector<int>> map(MAP_SIZE, vector<int>(MAP_SIZE));
    for(int i = 0; i < MAP_SIZE; i++){
        for(int j = 0; j < MAP_SIZE; j++){
            cin >> map[i][j];
            if(map[i][j] == 2){
                map[i][j] = -2; // empty place
                point_virus.push_back(make_tuple(i, j));
            }
            if(map[i][j] == 1){
                map[i][j] = -1; // wall
            }
        }
    }
    sort(point_virus.begin(), point_virus.end());

    do{
        auto cpy_map(map);
        queue<tuple<int, int>> put_virus;
        vector<vector<bool>> vis(MAP_SIZE, vector<bool>(MAP_SIZE));

        for(int i = 0; i < PUT_VIRUS; i++){
            auto [x, y] = point_virus[i];
            cpy_map[x][y] = 0;
            put_virus.push(point_virus[i]);
        }
        
        bool diff = true;
        while(diff){
            int dx[4] = {-1, 1, 0, 0};
            int dy[4] = {0, 0, -1, 1};
            diff = false;
            const int QUEUE_SIZE = put_virus.size();
            for(int i = 0; i < QUEUE_SIZE; i++){
                auto [x, y] = put_virus.front();
                put_virus.pop();
                for(int j = 0; j < 4; j++){
                    int nx = x + dx[j], ny = y + dy[j];
                    if(nx < 0 or nx >= MAP_SIZE or ny < 0 or ny >= MAP_SIZE) continue;
                    if(vis[nx][ny] or cpy_map[nx][ny] == -1) continue;
                    vis[nx][ny] = true;
                    cpy_map[nx][ny] = cpy_map[x][y] + 1;
                    diff = true;
                    put_virus.push(make_tuple(nx, ny));
                }
            }
        }

        int tmp_ans = 0;
        for(int i = 0; i < MAP_SIZE; i++){
            for(int j = 0; j < MAP_SIZE; j++){
                if(cpy_map[i][j] == -2){
                    tmp_ans = ERROR_ANS;
                }
                tmp_ans = max(cpy_map[i][j], tmp_ans);
            }
        }
        if(tmp_ans != ERROR_ANS) ans = min(tmp_ans, ans);
    }while(next_permutation(point_virus.begin(), point_virus.end()));

    if(ans == ERROR_ANS) cout << -1 << "\n";
    else cout << ans << "\n";
    return 0;
}