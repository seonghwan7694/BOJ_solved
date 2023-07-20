#include <bits/stdc++.h>
using namespace std;

int N, K;
bool vis[500001][2];
queue<pair<int, int>> q; // {x, t}

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> K;
    vis[N][0] = true;
    q.push({N, 0});

    while(!q.empty()){
        int now = q.front().first;
        int time = q.front().second;
        int pos = K + time * (time + 1) / 2;
        q.pop();

        if(pos > 500000){
            cout << -1 << "\n";
            break;
        }

        if(now == pos or vis[pos][time%2]){
            cout << time << "\n";
            break;
        }
        for(int next : {now - 1, now + 1, 2 * now}){
            if(next >= 0 and next <= 500000 and !vis[next][(time + 1)%2]){
                q.push({next, time + 1});
                vis[next][(time+1)%2] = true;
            }
        }

    }

    return 0;
}