#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll N, M;
ll w, x, y, c;
ll a1, b1, a2, b2;
ll tree[1025][1025], arr[1025][1025];

void update(int x, int y, ll num) {
    for(int i = x; i <= N; i += (-i & i)){
        for(int j = y; j <= N; j += (-j & j)){
            tree[i][j] += num;
        }
    }
}

ll sum(int x, int y) {
    ll tmp = 0;
    for(int i = x; i > 0; i -= (-i & i)){
        for(int j = y; j > 0; j -= (-j & j)){
            tmp += tree[i][j];
        }
    }
    return tmp;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> arr[i][j];
            update(i, j, arr[i][j]);
        }
    }
    while(M--){
        cin >> w;
        if(w == 0){
            cin >> x >> y >> c;
            update(x, y, c - arr[x][y]);
            arr[x][y] = c;
        }else{
            cin >> a1 >> b1 >> a2 >> b2;
            cout << sum(a2, b2) + sum(a1 - 1, b1 - 1) - sum(a2, b1 - 1) - sum(a1 - 1, b2) << "\n";
        }
    }
    return 0;
}