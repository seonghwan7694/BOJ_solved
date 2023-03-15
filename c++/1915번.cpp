#include <bits/stdc++.h>
using namespace std;

int n, m, res;
int board[1010][1010];

int main(){
    ios::sync_with_stdio(false);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        string str;
        cin >> str;
        for(int j = 1; j <= m; j++){
            board[i][j] = str[j - 1] - '0'; 
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(board[i][j] == 1) board[i][j] = min(board[i-1][j-1], min(board[i-1][j], board[i][j-1])) + 1;
            res = max(board[i][j], res);
        }
    }
    cout << res*res << "\n";
    return 0;
}