#include <bits/stdc++.h>
using namespace std;

int N, board[7][7];
vector<pair<int, int>> T;

bool check(){
    for(auto [x, y] : T){
        int xx = x, yy= y;
        // up
        while(--xx >= 0){
            if(board[xx][yy] == -1) break;
            if(board[xx][yy] == 1) return false;
        }
        // down
        xx = x, yy= y;
        while(++xx < N){
            if(board[xx][yy] == -1) break;
            if(board[xx][yy] == 1) return false;
        }
        // left
        xx = x, yy= y;
        while(++yy < N){
            if(board[xx][yy] == -1) break;
            if(board[xx][yy] == 1) return false;
        }
        // right
        xx = x, yy= y;
        while(--yy >= 0){
            if(board[xx][yy] == -1) break;
            if(board[xx][yy] == 1) return false;
        }
    }
    return true;
}
void func(int wall){
    if(wall == 3){
        if(check()){
            cout << "YES" << "\n";
            exit(0);
        }
        return;
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(board[i][j] == 0){
                board[i][j] = -1;
                func(wall + 1);
                board[i][j] = 0;
            }
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            char ch;
            cin >> ch;
            if(ch == 'T'){
                board[i][j] = 2;
                T.push_back({i, j});
            }
            if(ch == 'S') board[i][j] = 1;
        }
    }
    func(0);
    cout << "NO" << "\n";
    return 0;
}
