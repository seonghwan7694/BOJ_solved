#include <bits/stdc++.h>
#include <vector>
using namespace std;
int n, m, Q, _c, _dx, _dy, _x, _y, cnt;
vector<vector<int>> v;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> Q;
    v = vector<vector<int>>(n, vector<int>(m, 0));
    cnt = n * m;
    while(Q--){
        cin >> _c;
        if(_c == 1){
            cin >> _dx >> _dy >> _x >> _y;
            _x--, _y--;
            while(v[_x][_y] == 0){
                cnt--;
                v[_x][_y] = 1;
                if(_x + _dx < 0 or _x + _dx >= n) break;
                if(_y + _dy < 0 or _y + _dy >= m) break;
                _x += _dx;
                _y += _dy;
            }
        }else if(_c == 2){
            cin >> _x >> _y;
            cout << v[_x - 1][_y - 1] << "\n";
        }else{
            cout << cnt << "\n";
        }
    }
    return 0;
}