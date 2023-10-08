#include <bits/stdc++.h>
using namespace std;
#define block_updown true,true,false,false
#define block_minus false,false,true,true
#define block_plus true,true,true,true
#define block_one false,true,false,true
#define block_two true,false,false,true
#define block_three true,false,true,false
#define block_four false,true,true,false
#define DEBUG 0
tuple<bool, bool, bool, bool> block[7] = {
    {block_updown},
    {block_minus},
    {block_plus},
    {block_one},
    {block_two},
    {block_three},
    {block_four}
};

int R, C;
int board[25][25];
bool vis[25][25];
tuple<bool, bool, bool, bool> block_ans;
pair<int, int> M, Z, IDX;
tuple<bool, bool, bool, bool> can_flow[25][25]; // {up, down, left, right}
int dx[4] = {-1, 1, 0, 0}; // {up, down, left, right}
int dy[4] = {0, 0, -1, 1};
vector<pair<int, int>> gas;
bool area(int x, int y){
    return !(x < 0 or x >= R or y < 0 or y >= C);
}

void init(pair<int, int> start){
    if(area(start.first + dx[0], start.second + dy[0])){
        if(get<1>(can_flow[start.first + dx[0]][start.second + dy[0]])){ // up block can flow down
            get<0>(can_flow[start.first][start.second]) = true;
        }
    }
    if(area(start.first + dx[1], start.second + dy[1])){
        if(get<0>(can_flow[start.first + dx[1]][start.second + dy[1]])){ // down block can flow up
            get<1>(can_flow[start.first][start.second]) = true;
        }
    }
    if(area(start.first + dx[2], start.second + dy[2])){
        if(get<3>(can_flow[start.first + dx[2]][start.second + dy[2]])){ // left block can flow right
            get<2>(can_flow[start.first][start.second]) = true;
        }
    }
    if(area(start.first + dx[3], start.second + dy[3])){
        if(get<2>(can_flow[start.first + dx[3]][start.second + dy[3]])){ // right block can flow left
            get<3>(can_flow[start.first][start.second]) = true;
        }
    }
    vis[start.first][start.second] = true;
}

void BFS(pair<int, int> start){
    queue<pair<int, int>> q;
    q.push(start);
    vis[start.first][start.second] = true;
    

    while(!q.empty()){
        auto cur = q.front();
        int x = cur.first;
        int y = cur.second;
        q.pop();

        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if(!area(nx, ny) or vis[nx][ny]) continue;
            if(dir == 0 and get<0>(can_flow[x][y])){ // go to up
                if(get<1>(can_flow[nx][ny])){
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                }else{
                    IDX = {nx, ny};
                    gas.push_back({x, y});
                }
            }
            if(dir == 1 and get<1>(can_flow[x][y])){ // go to down
                if(get<0>(can_flow[nx][ny])){
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                }else{
                    IDX = {nx, ny};
                    gas.push_back({x, y});
                }
            }
            if(dir == 2 and get<2>(can_flow[x][y])){ // go to left
                if(get<3>(can_flow[nx][ny])){
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                }else{
                    IDX = {nx, ny};
                    gas.push_back({x, y});
                }
            }
            if(dir == 3 and get<3>(can_flow[x][y])){ // go to right
                if(get<2>(can_flow[nx][ny])){
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                }else{
                    IDX = {nx, ny};
                    gas.push_back({x, y});
                }
            }
        }
   }
   return;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        string str;
        cin >> str;
        for(int j = 0; j < C; j++){
            board[i][j] = str[j];
            if(str[j] == 124) can_flow[i][j] = tuple(block_updown);
            if(str[j] == '-') can_flow[i][j] = tuple(block_minus);
            if(str[j] == '+') can_flow[i][j] = tuple(block_plus);
            if(str[j] == '1') can_flow[i][j] = tuple(block_one);
            if(str[j] == '2') can_flow[i][j] = tuple(block_two);
            if(str[j] == '3') can_flow[i][j] = tuple(block_three);
            if(str[j] == '4') can_flow[i][j] = tuple(block_four);
            if(str[j] == 'Z'){
                can_flow[i][j] = tuple(false, false, false, false);
                Z = {i, j};
            }
            if(str[j] == 'M'){
                can_flow[i][j] = tuple(false, false, false, false);
                M = {i, j};
            }
        }
    }
    init(M), init(Z);
    BFS(M), BFS(Z);
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(!vis[i][j] and board[i][j] != '.') BFS({i, j});
        }
    }
    gas.erase(unique(gas.begin(), gas.end()), gas.end());

    for(int i = 0; i < 4; i++){
        if(find_if(gas.begin(), gas.end(), [&](const pair<int, int> &idx){
            return IDX.first + dx[i] == idx.first and IDX.second + dy[i] == idx.second;
        }) != gas.end()){
            if(i == 0) get<0>(block_ans) = true;
            if(i == 1) get<1>(block_ans) = true;
            if(i == 2) get<2>(block_ans) = true;
            if(i == 3) get<3>(block_ans) = true;
        };
    }
    
    
    cout << IDX.first + 1 << " " << IDX.second + 1 << " ";
    for(int i = 0; i < 7; i++){
        if(block_ans == block[i]){
            if(i == 0) cout << (char) 124;
            if(i == 1) cout << '-';
            if(i == 2) cout << '+';
            if(i == 3) cout << '1';
            if(i == 4) cout << '2';
            if(i == 5) cout << '3';
            if(i == 6) cout << '4';
            cout << "\n";
        }
    }
    if(DEBUG) cout << "\n\n";
    if(DEBUG){ for(int i = 0; i < R; i++){ for(int j = 0; j < C; j++){ int cnt = 0; auto [one, two, three, four] = can_flow[i][j]; if(one) cnt++; if(two) cnt++; if(three) cnt++; if(four) cnt++; cout << cnt; } cout << "\n"; } cout << "\n\n"; for(int i = 0; i < R; i++){ for(int j = 0; j < C; j++){ cout << vis[i][j]; } cout << "\n"; } }
    return 0;
}