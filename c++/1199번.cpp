#include <bits/stdc++.h>
using namespace std;

int N;
int degree[1010];
int adj[1010][1010];
vector<int> res;
vector<int> graph[1010];


void func(int pos){
    for(auto nxt : graph[pos]){
        if(adj[pos][nxt]){
            adj[pos][nxt]--;
            adj[nxt][pos]--;
            func(nxt);
        }
    }
    res.push_back(pos);
    return;
}

/*
void f(int pos){
    stack s;
    s.push(pos);
    int upd = 0;
    while (!s.empty()) {
        upd = 0;
        pos = s.top();
        while (!graph[pos].empty()) {
            long long r = graph[pos].front()%100;
            graph[pos].pop_front();
            s.push((int)r);
            upd = 1;
            break;
        }
        if(upd == 1) continue;
        s.pop();
        res.push_back(pos);
    }
}
*/
void f(int pos){
    stack<int> s;
    s.push(pos);
    int upd = 0;
    while(!s.empty()){
        pos = s.top();
        upd = 0;
        while(!graph[pos].empty()){
            int nxt = graph[pos].back();
            graph[pos].pop_back();
            if(adj[pos][nxt]){
                adj[pos][nxt]--;
                adj[nxt][pos]--;
                upd = 1;
                s.push(nxt);
                break;
            }
        }
        if(upd == 1) continue; 
        s.pop();
        res.push_back(pos);
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N;

    for(int i = 0, c; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> c;     
            adj[i][j] = c;
            if(adj[i][j] == 0) continue;
            degree[i] += adj[i][j];
            while(c--) graph[i].push_back(j);
        }
    }
    
    for(int i = 0; i < N; i++){
        if(degree[i] & 1){
            cout << -1 << "\n" ;
            return 0;
        }
    }

    f(0);
    for(auto x : res) cout << x + 1 << " ";
    cout << "\n";

    return 0;
}