#include <bits/stdc++.h>
#include <tuple>
using namespace std;
#define EAST 1
#define WEST 2
#define SOUTH 3
#define NORTH 4
pair<int, int> DIR[5] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int N, M;
int board[111][111];
bool vis[111][111][5];

int rotate_left(int dir){
    if(dir == EAST){
        return NORTH;
    }
    if(dir == NORTH){
        return WEST;
    }
    if(dir == WEST){
        return SOUTH;
    }
    return EAST;
}

int rotate_right(int dir){
    if(dir == EAST){
        return SOUTH;
    }
    if(dir == SOUTH){
        return WEST;
    }
    if(dir == WEST){
        return NORTH;
    }
    return EAST;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> board[i][j];
        }
    }
    int st_x, st_y, st_dir;
    int en_x, en_y, en_dir;
    cin >> st_x >> st_y >> st_dir;
    cin >> en_x >> en_y >> en_dir;
    queue<tuple<int, int, int, int>> q;
    q.push(make_tuple(st_x, st_y, st_dir, 0));
    vis[st_x][st_y][st_dir] = true;
    while(!q.empty()){
        auto [x, y, dir, cnt] = q.front();
        q.pop();
        if(x == en_x and y == en_y and dir == en_dir){
            cout << cnt << "\n";
            break;
        }
        int nx, ny, ndir, ncnt;

        { // GO FRONT
            for(int bias = 1; bias <= 3; bias++){
                nx = x + DIR[dir].first * bias;
                ny = y + DIR[dir].second * bias;
                ndir = dir;
                ncnt = cnt + 1;
                if(1 <= nx and nx <= N and 1 <= ny and ny <= M){
                    if(board[nx][ny] == 1) break;
                    if(vis[nx][ny][ndir] == false){
                        q.push(make_tuple(nx, ny, ndir, ncnt));
                        vis[nx][ny][ndir] = true;
                    }
                }
            }
       }

        { // ROTATE LEFT
            nx = x;
            ny = y;
            ndir = rotate_left(dir);
            ncnt = cnt + 1;
            if(vis[nx][ny][ndir] == false){
                q.push(make_tuple(nx, ny, ndir, ncnt));
                vis[nx][ny][ndir] = true;
            }
        }

        { // ROTATE RIGHT
            nx = x;
            ny = y;
            ndir = rotate_right(dir);
            ncnt = cnt + 1;
            if(vis[nx][ny][ndir] == false){
                q.push(make_tuple(nx, ny, ndir, ncnt));
                vis[nx][ny][ndir] = true;
            }
        }
    }

    return 0;
}