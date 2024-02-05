#include <bits/stdc++.h>
using namespace std;
#define INF 976453
int v[11][11];
int res = INF;
int paper[6] = {0, 5, 5, 5, 5, 5};

bool is_possible(int x, int y, int k){
    if(x + k > 10 or y + k > 10) return false;
    for(int i = x; i < x + k; i++){
        for(int j = y; j < y + k; j++){
            if(!v[i][j]) return false;
        }
    }
    return true;
}

void custom_fill(int x, int y, int k, int val){
    for(int i = x; i < x + k; i++){
        for(int j = y; j < y + k; j++){
            v[i][j] = val;
        }
    }
}

bool fill_check(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(v[i][j]) return false;
        }
    }
    return true;
}

void func(int d){
    if(d > res){
        return;
    }
    if(fill_check()){
        res = min(res, d);
        return;
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(v[i][j]){
                for(int k = 5; k >= 1; k--){
                    if(paper[k] <= 0) continue;
                    if(is_possible(i, j, k)){
                        paper[k]--;
                        custom_fill(i, j, k, 0);
                        func(d + 1);
                        custom_fill(i, j, k, 1);
                        paper[k]++;
                    }
                }
                return;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin >> v[i][j];
        }
    }
    func(0);
    cout << (res == INF ? -1 : res) << "\n";
    return 0;
}