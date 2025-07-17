#include <iostream>

using namespace std;
int N;
char ch[400][400];

void func(int x, int y, int h){
    if(h == 1){
        ch[x][y] = '*';       
        return;
    }
    // 4h - 3
    for(int i = x; i < x + 4 * h - 3; i++){
        ch[i][y] = '*';
        ch[x][i] = '*';
        ch[i][y + 4 * h - 4] = '*';
        ch[x + 4 * h - 4][i] = '*';
    }
    func(x + 2, y + 2, h - 1);
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    func(0, 0, N);
    for(int i = 0; i < 4 * N - 3; i++){
        for(int j = 0; j < 4 * N - 3; j++){
            cout << (ch[i][j] == '*' ? '*' : ' ');
        }
        cout << "\n";
    }
    return 0;
}