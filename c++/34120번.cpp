#include <iostream>
#include <vector>
#include <queue>
#define ll long long
#define INF 987654321
using namespace std;


ll N, M, A, B, T[2020];
bool C[2020], F[2020]; // true -> windows
vector<pair<ll, ll>> g[2020];

bool eyes_closed(ll t, ll w){ // 구간 [t, w]에서 눈을 닫고 있는가?
    // 어떤 방식으로든 한 주기를 넘으면 눈 뜬 때가 존재함.
    if((t / (A + B)) != ((t + w) / (A + B))) return false; 
    if((t % (A + B) > A)) return false;
    if(((t + w) % (A + B) > A)) return false;
    return true;
}


void dijkstra(){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0, 1}); // {t, v}
    T[1] = 0;
    while(!pq.empty()){
        auto [t, u] = pq.top(); // 시간 t인 시점에 u 건물에 있다. 시점 t는 감은 상태거나, 뜨고 있지만 창문이 없는 두 가지 경우 중 하나이다.
        pq.pop();
        if(eyes_closed(t, 0) == false and C[u] == 1) continue;

        if(u == N){
            cout << t << "\n";
            return;
        }

        for(auto [v, w] : g[u]){
            if(A < w) continue;
            if(!F[u] and C[u] == false and !eyes_closed(t, w)){ // 창문은 없으나, 건널 수 없으면 다음 주기를 기다린다.
                F[u] = true;
                pq.push({(t / (A + B) + 1) * (A + B), u});
            }
            if(T[v] > t + w and eyes_closed(t, w)){
                T[v] = t + w;
                pq.push({t + w, v});
            }
        }
    }
    cout << -1 << "\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    fill(T, T + 2020, INF);
    for(int m = 0, u, v, w; m < M; m++){
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    for(int i = 1; i <= N; i++){
        cin >> C[i];
    }
    cin >> A >> B;
    dijkstra();
    return 0;
}