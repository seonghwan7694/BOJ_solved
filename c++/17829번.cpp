#include <iostream>
#include <vector>
using namespace std;

int N, b[1025][1025];

int func(int x, int y, int n){
    if(n == 2){
        vector<int> t;
        t.push_back(b[x][y]);
        t.push_back(b[x+1][y]);
        t.push_back(b[x][y+1]);
        t.push_back(b[x+1][y+1]);
        sort(t.begin(), t.end());
        return t[2];
    }
    vector<int> t;
    int half = n / 2;
    t.push_back(func(x, y, half));
    t.push_back(func(x + half, y, half));
    t.push_back(func(x, y + half, half));
    t.push_back(func(x + half, y + half, half));
    sort(t.begin(), t.end());
    return t[2];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) cin >> b[i][j];
    cout << func(0, 0, N) << "\n";
}