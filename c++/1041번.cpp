#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define lld long long int
/*

1면 : (N - 2) * (N - 2) * 5 + (N - 2) * 4
2면 : (N - 2) * 8
3면 : 4개 고정
3 x 3 일때
왼쪽 : A A A  A A A  A A A
오른쪽 : F F F  F F F  F F F

1. c++ -> 자료구조
2.c -> 자료구조, 알고리즘
*/

vector<lld> dice(6, 0);
lld N, a, b, c, min_three, min_two, A, B, C, D, E, F;

int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < 6; i++){
        cin >> dice[i];
    }
    
    A = dice[0], B = dice[1], C = dice[2], D = dice[3], E = dice[4], F = dice[5];
    
    min_two = min({A + B, A + C, A + D, A + E, B + C, B + D, B + F, C + E, C + F, D + E, D + F, E + F});

    min_three = min({A + D + E, A + B + D, A + C + E, A + B + C, B + C + F, B + D + F, C + B + F, C + E + F, D + E + F});


    if(N == 1){
        sort(dice.begin(), dice.end());
        cout << dice[0] + dice[1] + dice[2] + dice[3] + dice[4] << "\n";
        return 0;
    }else if(N == 2){
        a = 0;
        b = 4;
        c = 4;
    }else {
        b = (N - 1) * 4 + (N - 2) * 4; // 2개면
        c = 4; // 3개 면
        a = (N - 2)*(N - 2) * 5 + (N - 2) * 4; // 1개 면
    }
    cout << a * (*min_element(dice.begin(), dice.end())) + b * min_two + c * min_three << "\n";
    return 0;
}