#include <bits/stdc++.h>
using namespace std;
#define FLOWER 5
#define GREEN 3
#define RED 4
#define EMPTY 1 
int N, M, G, R, res;
int MAP[50][50];
vector<pair<int, int>> CAN_FLOOD;
bool VIS_CAN_FLOOD[10];

int SIMULATION(){
    int cpy_MAP[50][50];
    queue<pair<int, int>> q;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cpy_MAP[i][j] = MAP[i][j];
            if(cpy_MAP[i][j] == GREEN or cpy_MAP[i][j] == RED) q.push({i, j});
        }
    }


    while(!q.empty()){
        pair<bool, bool> can_flower[50][50]; // {GREEN, RED}

        for(int q_size = 0; q_size < q.size(); q_size++){
            auto [cur_x, cur_y] = q.front();
            q.pop();


        }
    }
}

void func(int g, int r){
    if(g == G and r == R){
        res = max(res, SIMULATION());
        return; 
    }

    if(g < G){
        for(int i = 0; i < CAN_FLOOD.size(); i++){
            if(!VIS_CAN_FLOOD[i]){
                VIS_CAN_FLOOD[i] = true;
                MAP[CAN_FLOOD[i].first][CAN_FLOOD[i].second] = GREEN;

                func(g + 1, r);

                MAP[CAN_FLOOD[i].first][CAN_FLOOD[i].second] = EMPTY;
                VIS_CAN_FLOOD[i] = false;
            }
        }
    }
    if(r < R){
        for(int i = 0; i < CAN_FLOOD.size(); i++){
            if(!VIS_CAN_FLOOD[i]){
                VIS_CAN_FLOOD[i] = true;
                MAP[CAN_FLOOD[i].first][CAN_FLOOD[i].second] = RED;

                func(g, r + 1);

                MAP[CAN_FLOOD[i].first][CAN_FLOOD[i].second] = EMPTY;
                VIS_CAN_FLOOD[i] = false;
            }
        }
    }
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

    func(0, 0);
    cout << res << "\n";
    return 0;
}