#include <bits/stdc++.h>
using namespace std;

int N;
bool board[10][10];
bool rd[19], ld[19];
int ans[2], idx;

void func(int x, int y, int k){
    if(y >= N){
        x++;
        y = y & 1 ? 0 : 1;
    }
    if(x >= N){
        ans[idx] = max(k, ans[idx]);
        return;
    }

    if(board[x][y] and !rd[x + y] and !ld[N - 1 + y - x]){
        rd[x + y] = ld[N - 1 + y - x] = true;
        func(x, y + 2, k + 1);
        rd[x + y] = ld[N - 1 + y - x] = false;
    }
    func(x, y + 2, k);
}

int main(){
    ios::sync_with_stdio(false);

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }
    func(0, 0, 0);
    idx++;
    func(0, 1, 0);
    cout << ans[0] + ans[1] << "\n";
    return 0;
}