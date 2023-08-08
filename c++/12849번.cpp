#include <bits/stdc++.h>
using namespace std;
#define DIV 1'000'000'000 + 7

/*
D = 1 -> 0
D = 2 -> 2
// 정보대 -> 전산관(1) -> 정보대, 정보대 -> 미래관(1) -> 정보대
D = 3 -> 2
// 정보대 -> 미래관(1) -> 전산관(1) -> 정보대
// 정보대 -> 전산관 -> 미래관  -> 정보대
D = 4
*/

/*
0 - 정보과학관
1 - 전산관
2 - 미래관
3 - 신앙관
4 - 한경직기념관
5 - 진리관
6 - 학생회관
7 - 형남공학관

*/

vector<int> graph[8] = {
    [0] = {1, 3},
    [1] = {0, 2, 3},
    [2] = {1, 3, 4, 5},
    [3] = {0, 1, 2, 5},
    [4] = {2, 5, 6},
    [5] = {2, 3, 4, 7},
    [6] = {4, 7},
    [7] = {5, 6}
};

long long int dp[8] = {1, 0, 0, 0, 0, 0, 0, 0}, state[8];

int D;
int main(){
    ios::sync_with_stdio(false);
    cin >> D;

    for(int d = 0; d < D; d++){
        for(int i = 0; i < 8; i++){
            for(auto x : graph[i]) state[i] = (dp[x] + state[i])%DIV;
        }
        for(int i = 0; i < 8; i++) dp[i] = state[i] % DIV;
    }
    cout << dp[0] << "\n";
    return 0;
}