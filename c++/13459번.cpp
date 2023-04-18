#include <bits/stdc++.h>
#include <tuple>
#include <utility>

using namespace std;
#define PII pair<int, int>
string board[10];
bool vis[10][10][10][10];
int N, M;
PII O;
PII dir[4] = {{-1 ,0}, {1, 0}, {0, -1}, {0, 1}};

bool canmove(int x, int y, int D, int xx, int yy){
    auto [dx, dy] = make_pair(dir[D].first, dir[D].second);
    int nx = x + dx;
    int ny = y + dy;
    if(board[nx][ny] == '#') return false;
    if(nx == xx and ny == yy) return false;
    return true;
}

tuple<int, int, int, int> swipe(int rx, int ry, int bx, int by, int D){
    auto [dx, dy] = make_pair(dir[D].first, dir[D].second);
    bool r = false, b = false;
    while(true){
        if(rx != -1 and ry != -1){
            r = canmove(rx, ry, D, bx, by);
        }else{
            r = false;
        }

        if(bx != -1 and by != -1){
            b = canmove(bx, by, D, rx, ry);
        }else{
            b = false;
        }

        if(r && b){
            rx += dx; ry += dy;
            bx += dx; by += dy;
        }else if(r){
            rx += dx; ry += dy;
            if(bx != -1 and by != -1) b = canmove(bx, by, D, rx, ry);
            else b = false;

            if(b){
                bx += dx; by += dy;
            }
        }else if(b){
            bx += dx; by += dy;
            if(rx != -1 and ry != -1) r = canmove(rx, ry, D, bx, by);
            else r = false;
            if(r){
                rx += dx; ry += dy;
            }
        }else{
            break;
        }
        if(O.first == bx and O.second == by){
            b = true;
            bx = -1; by = -1;
        }
        if(O.first == rx and O.second == ry){
            r = true;
            rx = -1; ry = -1;
        }
    }
    return make_tuple(rx, ry, bx, by);
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> M;

    PII R, B;
    for(int i = 0; i < N; i++){
        cin >> board[i];
        for(int j = 0; j < M; j++){
            if(board[i][j] == 'R'){ R = {i, j}; board[i][j] = '.'; }
            if(board[i][j] == 'B'){ B = {i, j}; board[i][j] = '.'; }
            if(board[i][j] == 'O'){ O = {i, j}; board[i][j] = '.'; }
        }
    }

    queue<tuple<int, int, int, int, int>> q;

    q.push(make_tuple(R.first, R.second, B.first, B.second, 1));
    vis[R.first][R.second][B.first][B.second] = true;

    while(!q.empty()){
        auto [rx, ry, bx, by, k] = q.front();
        q.pop();

        if(k > 10){
            break;
        }

        for(int i = 0; i < 4; i++){
            auto [nrx, nry, nbx, nby] = swipe(rx, ry, bx, by, i);
            if(nrx == -1 and nry == -1 and nbx == -1 and nby == -1) continue;
            if(nbx == -1 and nby == -1) continue;
            if(nrx == -1 and nry == -1){
                cout << 1 << "\n";
                return 0;
            } 
            if(!vis[nrx][nry][nbx][nby]){
                q.push(make_tuple(nrx, nry, nbx, nby, k + 1));
                vis[nrx][nry][nbx][nby] = true;
            }
        }
    }
    cout << 0 << "\n";
    return 0;
}