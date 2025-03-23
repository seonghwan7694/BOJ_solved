#include <bits/stdc++.h>
using namespace std;

int A, B, N, M, ret, vis[101010];
queue<int> q;
void scale(int n){
    if(0 <= n and n <= 100000 and !vis[n]){
        vis[n] = true;
        q.push(n);
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);

    cin >> A >> B >> N >> M;
    q.push(N);
    while(true){
        int Q_SIZE = q.size();
        for(int i = 0; i < Q_SIZE; i++){
            int t = q.front(); q.pop();
            if(t == M){
                cout << ret << "\n";
                return 0;
            }
            scale(t + 1); scale(t - 1);
            scale(t + A); scale(t - A);
            scale(t + B); scale(t - B);
            scale(t * B); scale(t * A);
        }
        ret++;
    }


    return 0;
}