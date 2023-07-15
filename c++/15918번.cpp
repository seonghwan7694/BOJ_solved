#include <bits/stdc++.h>
using namespace std;

int n, x, y, ans;
vector<int> v(25, -1);
bool isUsed[25];

#define DEBUG 1
void dfs(int x){
    if(x == 2 * n){
        ans++;
        return;
    }
    if(v[x] == -1){
        for(int i = 1; i <= n; i++){
            if(isUsed[i] == false and x+i+1 <= 2 * n and v[x+i+1] == -1){
                v[x] = v[x+i+1] = i;
                isUsed[i] = true;
                dfs(x+1);
                isUsed[i] = false;
                v[x] = v[x+i+1] = -1;
            }
        }
    }else{
        dfs(x + 1);
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> n >> x >> y;
    v[x] = v[y] = y - x - 1;
    isUsed[y - x - 1] = true;
    dfs(1);
    cout << ans << "\n";
    return 0;
}   