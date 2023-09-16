#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define FLOWER 5
#define GREEN 3
#define RED 4
#define EMPTY 1 
#define DEBUG 0

int N, M, G, R, res;
int MAP[50][50];
vector<pair<int, int>> CAN_FLOOD;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int SIMULATION(){
    if(DEBUG) for(int i = 0; i < G + R; i++){ cout << CAN_FLOOD[i].first << ", " << CAN_FLOOD[i].second; if(MAP[CAN_FLOOD[i].first][CAN_FLOOD[i].second] == GREEN) cout << "G"  << " / "; if(MAP[CAN_FLOOD[i].first][CAN_FLOOD[i].second] == RED) cout << "R"  << " / "; }

    int cpy_MAP[N][M], r = 0;
    queue<tuple<int, int, int>> q;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cpy_MAP[i][j] = MAP[i][j];
            if(cpy_MAP[i][j] == GREEN or cpy_MAP[i][j] == RED) q.push({i, j, cpy_MAP[i][j]});
        }
    }


    while(!q.empty()){
        int Q_SIZE = q.size();
        pair<bool, bool> tmp_MAP[N][M];
        for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) tmp_MAP[i][j] = {0, 0};

        for(int q_size = 0; q_size < Q_SIZE; q_size++){
            auto [cur_x, cur_y, cur_color] = q.front();
            q.pop();

            for(int dir = 0; dir < 4; dir++){
                int nx = cur_x + dx[dir];
                int ny = cur_y + dy[dir];
                if(nx < 0 or nx >= N or ny < 0 or ny >= M) continue;
                if(cpy_MAP[nx][ny] == EMPTY){
                    if(cur_color == GREEN){ tmp_MAP[nx][ny] = {1, tmp_MAP[nx][ny].second}; }
                    if(cur_color == RED){ tmp_MAP[nx][ny] = {tmp_MAP[nx][ny].first, 1}; }
                }
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(cpy_MAP[i][j] != EMPTY) continue;

                if(tmp_MAP[i][j].first and tmp_MAP[i][j].second) cpy_MAP[i][j] = FLOWER;
                else if(tmp_MAP[i][j].first and !tmp_MAP[i][j].second){
                    cpy_MAP[i][j] = GREEN;
                    q.push({i, j, GREEN});
                }
                else if(!tmp_MAP[i][j].first and tmp_MAP[i][j].second){
                    cpy_MAP[i][j] = RED;
                    q.push({i, j, RED});
                }
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(cpy_MAP[i][j] == FLOWER) r++;
        }
    }
    if(DEBUG) cout << "\n";
    return r;
}

void func(){
    vector<int> IDX(CAN_FLOOD.size(), 0);
    for(int i = 0; i < G; i++){ IDX[i] = GREEN; }
    for(int i = G; i < G + R; i++){ IDX[i] = RED; }
    sort(IDX.begin(), IDX.end()); // {0, 0, 0, GREEN, GREEN, RED, RED}

    do{
        for(int i = 0; i < IDX.size(); i++){
            if(IDX[i] == GREEN) MAP[CAN_FLOOD[i].first][CAN_FLOOD[i].second] = GREEN;
            if(IDX[i] == RED) MAP[CAN_FLOOD[i].first][CAN_FLOOD[i].second] = RED;
        }
        res = max(res, SIMULATION());
        for(int i = 0; i < IDX.size(); i++){
            MAP[CAN_FLOOD[i].first][CAN_FLOOD[i].second] = EMPTY;
        }
    }while(next_permutation(IDX.begin(), IDX.end()));
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> M >> G >> R;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> MAP[i][j];
            if(MAP[i][j] == 2){
                CAN_FLOOD.push_back({i, j});
                MAP[i][j] = 1;
            }
        }
    }

    // func(0, 0, 0, 0);
    func();
    cout << res << "\n";
    return 0;
}