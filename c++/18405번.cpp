#include <bits/stdc++.h>
using namespace std;

int N, K;
int S, X, Y;
int arr[202][202];
queue<pair<int, int>> virus[1010];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(){
    ios::sync_with_stdio();
    cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++){
        cin >> arr[i][j];
        if(arr[i][j] != 0) virus[arr[i][j]].push({i, j});
    }
    cin >> S >> X >> Y;
    for(int t = 0; t < S; t++){
        for(int k = 1; k <= K; k++){
            int sz = virus[k].size();
            for(int i = 0; i < sz; i++){
                auto cur = virus[k].front();
                virus[k].pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx < 1 or nx > N or ny < 1 or ny > N) continue;
                    if(arr[nx][ny] == 0){
                        arr[nx][ny] = k;
                        virus[k].push({nx, ny});
                    }
                }
            }
        }
    }

    cout << arr[X][Y] << "\n";
    return 0;
}