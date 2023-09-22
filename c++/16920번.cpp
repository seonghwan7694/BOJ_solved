#include <bits/stdc++.h>
using namespace std;
#define lld long long int
lld N, M, P;
lld S[10];
lld MAP[1010][1010];
lld ans[10];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<pair<int, int>> BOARDER[10];

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
        }
    }

    int delta = 0;
    while(true){

        FIND_BOARDER();

        for(int i = 1; i <= P; i++){
            for(auto &x : BOARDER[i]){
                queue<pair<pair<int, int>, int>> q;
                
                while(!q.empty()){
                    auto cur = q.front();
                    q.pop();
                    if(cur.second == 0) continue;
                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.first.first + dx[dir];
                        int ny = cur.first.second + dy[dir];
                        if(nx < 0 or nx > N or ny < 0 or ny > M) continue;
                        if(MAP[nx][ny]) continue;
                        MAP[nx][ny] = i;
                        delta++;
                        q.push({{nx, ny}, cur.second - 1});
                    }
                }
            }
        }
        if(delta == 0) break;
    }








    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            ans[MAP[i][j]]++;
        }
    }
    for(int i = 1; i <= P; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}