#include <bits/stdc++.h>
using namespace std;
#define lld long long int

lld T;

lld Map[101][101];
bool Vis[101][101];
lld h, w, ans;
lld key;
queue<pair<int, int>> q;
vector<pair<int, int>> door;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void border_detect(){
    for(int j = 0; j < w; j++){
        if(Vis[0][j] == false and Map[0][j] != -1){
            if('a' <= Map[0][j] and Map[0][j] <= 'z'){
                key = key | (1 << (Map[0][j] - 'a'));
                Vis[0][j] = true;
                q.push({0, j});
            }else if('A' <= Map[0][j] and Map[0][j] <= 'Z'){
                if((1 << (Map[0][j] - 'A')) & key){
                    Vis[0][j] = true;
                    q.push({0, j});
                }else{
                    door.push_back({0, j});
                }
            }else if(Map[0][j] == '$'){
                ans++;
                Vis[0][j] = true;
                q.push({0, j});
            }else if(Map[0][j] == 0){
                Vis[0][j] = true;
                q.push({0, j});
            }
        }
    }

    for(int j = 0; j < w; j++){
        if(Vis[h-1][j] == false and Map[h-1][j] != -1){
            if('a' <= Map[h-1][j] and Map[h-1][j] <= 'z'){
                key = key | (1 << (Map[h-1][j] - 'a'));
                Vis[h-1][j] = true;
                q.push({h-1, j});
            }else if('A' <= Map[h-1][j] and Map[h-1][j] <= 'Z'){
                if((1 << (Map[h-1][j] - 'A')) & key){
                    Vis[h-1][j] = true;
                    q.push({h-1, j});
                }else{
                    door.push_back({h-1, j});
                }
            }else if(Map[h-1][j] == '$'){
                ans++;
                Vis[h-1][j] = true;
                q.push({h-1, j});
            }else if(Map[h-1][j] == 0){
                Vis[h-1][j] = true;
                q.push({h-1, j});
            }
        }
    }

    for(int i = 1; i < h - 1; i++){
        if(Vis[i][0] == false and Map[i][0] != -1){
            if('a' <= Map[i][0] and Map[i][0] <= 'z'){
                key = key | (1 << (Map[i][0] - 'a'));
                Vis[i][0] = true;
                q.push({i, 0});
            }else if('A' <= Map[i][0] and Map[i][0] <= 'Z'){
                if((1 << (Map[i][0] - 'A')) & key){
                    Vis[i][0] = true;
                    q.push({i, 0});
                }else{
                    door.push_back({i, 0});
                }
            }else if(Map[i][0] == '$'){
                ans++;
                Vis[i][0] = true;
                q.push({i, 0});
            }else if(Map[i][0] == 0){
                Vis[i][0] = true;
                q.push({i, 0});
            }
        }
    }

    for(int i = 1; i < h - 1; i++){
        if(Vis[i][w-1] == false and Map[i][w-1] != -1){
            if('a' <= Map[i][w-1] and Map[i][w-1] <= 'z'){
                key = key | (1 << (Map[i][w-1] - 'a'));
                Vis[i][w-1] = true;
                q.push({i, w-1});
            }else if('A' <= Map[i][w-1] and Map[i][w-1] <= 'Z'){
                if((1 << (Map[i][w-1] - 'A')) & key){
                    Vis[i][w-1] = true;
                    q.push({i, w-1});
                }else{
                    door.push_back({i, w-1});
                }
            }else if(Map[i][w-1] == '$'){
                ans++;
                Vis[i][w-1] = true;
                q.push({i, w-1});
            }else if(Map[i][w-1] == 0){
                Vis[i][w-1] = true;
                q.push({i, w-1});
            }
        }
    }
}

void solved(){
    ans = 0;
    key = 0;
    memset(Map, 0, sizeof Map);
    memset(Vis, false, sizeof Vis);
    door.clear();
    while(!q.empty()) q.pop();

    cin >> h >> w;
    for(int i = 0; i < h; i++){
        string str;
        cin >> str;
        for(int j = 0; j < w; j++){
            if(str[j] == '.'){
                Map[i][j] = 0;
            }else if(str[j] == '*'){
                Map[i][j] = -1;
            }else{
                Map[i][j] = str[j];
            }
        }
    }
    string kkey;
    cin >> kkey;
    if(kkey != "0") for(auto &c : kkey){
        key = key | (1 << (c - 'a'));
    }

    border_detect();
    bool delta = false;

    while(true){
        for(auto &[x, y] : door){
            if(Vis[x][y]) continue;
            if(key & (1 << (Map[x][y] - 'A'))){
                q.push({x, y});
                Vis[x][y] = true;
                delta = true;
            }
        }

        while(!q.empty()){
            auto cur = q.front();
            q.pop();

            for(int dir = 0; dir < 4; dir++){
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if(nx < 0 or nx >= h or ny < 0 or ny >= w) continue;
                if(Vis[nx][ny] == false and Map[nx][ny] != -1){
                    if(Map[nx][ny] == 0){
                        q.push({nx, ny});
                        Vis[nx][ny] = true;
                        delta = true;
                    }else if(Map[nx][ny] == '$'){
                        ans++;
                        q.push({nx, ny});
                        Vis[nx][ny] = true;
                        delta = true;
                    }else if('a' <= Map[nx][ny] and Map[nx][ny] <= 'z'){
                        key = (1 << (Map[nx][ny] - 'a')) | key;
                        q.push({nx, ny});
                        Vis[nx][ny] = true;
                        delta = true;
                    }else if('A' <= Map[nx][ny] and Map[nx][ny] <= 'Z'){
                        if(key & (1 << (Map[nx][ny] - 'A'))){
                            q.push({nx, ny});
                            Vis[nx][ny] = true;
                            delta = true;
                        }else{
                            door.push_back({nx, ny});
                        }
                    }
                }
            }
        }
        for(auto &[x, y] : door){
            if(Vis[x][y]) continue;
            if(key & (1 << (Map[x][y] - 'A'))){
                q.push({x, y});
                Vis[x][y] = true;
                delta = true;
            }
        }

        if(delta == false) break;
        else delta = false;
    }
    
    cout << ans << "\n";


}

int main(){
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--){
        solved();
        // for(int i = 0; i < h; i++){ for(int j = 0; j < w; j++){ if(Vis[i][j]) cout << '.'; else cout << '*'; } cout << "\n"; }
    }


    return 0;
}