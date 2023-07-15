#include <algorithm>
#include <bits/stdc++.h>
#include <tuple>
#define INF 987654321
using namespace std;

vector<vector<vector<int>>> input_board;
vector<vector<vector<int>>> board;
int ans = INF;

vector<vector<int>> rotate(int depth, int roatation_depth, vector<vector<int>> &tmp_board){
    vector<vector<int>> new_tmp_board(5, vector<int>(5, 0));
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            new_tmp_board[i][j] = tmp_board[i][j];
        }
    }
    if(depth == roatation_depth){
        return new_tmp_board;
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            new_tmp_board[j][5 - i - 1] = tmp_board[i][j];
        }
    }
    return rotate(depth + 1, roatation_depth, new_tmp_board);
}

void rotate_board(){
    for(int k = 0; k < 5; k++){
        for(int r = 0; r < 4; r++){
            vector<vector<int>> tmp_board(5, vector<int>(5, 0));
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 5; j++){
                    tmp_board[i][j] = board[k][i][j];
                }
            }
            board.push_back(rotate(0, r, tmp_board));
        }
    }
}

void input(){
    input_board.resize(5);
    for(int k = 0; k < 5; k++){
        input_board[k].resize(5);
        for(int i = 0; i < 5; i++){
            input_board[k][i].resize(5);
            for(int j = 0; j < 5; j++){
                cin >> input_board[k][i][j];
            }
        }
    }
}

tuple<int, int, int> dir[6] = {
    make_tuple(0, 0, -1),
    make_tuple(0, -1, 0),
    make_tuple(0, 0, 1),
    make_tuple(0, 1, 0),
    make_tuple(1, 0, 0),
    make_tuple(-1, 0, 0)
};

void play_maze(vector<vector<vector<int>>> &maze){
    tuple<int, int, int> st[4] = {make_tuple(0, 0, 0), make_tuple(0, 0, 4), make_tuple(0, 4, 4), make_tuple(0, 4, 0)};
    tuple<int, int, int> en[4] = {make_tuple(4, 4, 4), make_tuple(4, 4, 0), make_tuple(4, 0, 0), make_tuple(4, 0, 4)};
    for(int opt = 0; opt < 4; opt++){
        auto [st_k, st_x, st_y] = st[opt];
        auto [en_k, en_x, en_y] = en[opt];
        if(maze[st_k][st_x][st_y] == 0 or maze[en_k][en_x][en_y] == 0) continue;

        queue<tuple<int, int, int, int>> q; // {k, x, y, cnt}
        bool maze_vis[5][5][5];

        q.push(make_tuple(st_k, st_x, st_y, 0));
        memset(maze_vis, false, sizeof maze_vis);

        while(!q.empty()){
            auto [k, x, y, cnt] = q.front(); 
            q.pop();
            if(x == en_x and y == en_y){
                ans = min(ans, cnt);
                break;
            }

            for(int d = 0; d < 6; d++){
                auto [dk, dx, dy] = dir[d];
                int nk = k + dk;
                int nx = x + dx;
                int ny = y + dy;
                int ncnt = cnt + 1;
                if((nk < 0 or nk >= 5) or (nx < 0 or nx >= 5) or (ny < 0 or ny >= 5)) continue;
                if(maze_vis[nk][nx][ny]) continue;
                maze_vis[nk][nx][ny] = true;
                q.push(make_tuple(nk, nx, ny, ncnt));
            }
        }

    }
}

bool Floor[5]; // {floor}
bool Rotate[5][4]; // [floor, rotate]
void make_maze(int depth, vector<vector<vector<int>>> &maze){
    if(depth == 5){
        play_maze(maze);
    }

    for(int i = 0; i < 5; i++){
        if(!Floor[i]){
            Floor[i] = true;
            for(int j = 0; j < 4; j++){
                if(!Rotate[i][j]){
                    Rotate[i][j] = true;
                    maze.push_back(board[i * 4 + j]);
                    make_maze(depth + 1, maze);
                    maze.pop_back();
                    Rotate[i][j] = false;
                }
            }
            Floor[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    input();
    rotate_board();
    vector<vector<vector<int>>> empty_maze;
    make_maze(0, empty_maze);
    if(ans == INF){
        cout << -1 << "\n";
    }else{
        cout << ans << "\n";
    }
    return 0;
}