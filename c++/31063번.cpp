#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, M;
vector<ll> COW;

void eat_candy_cane(){
    ll height, eaten_height = 0, prev_cow;
    cin >> height;

    for(auto &cow : COW){
        if(height == eaten_height) break;
        if(cow > eaten_height){
            prev_cow = cow;
            cow += min(height, cow) - eaten_height;
            eaten_height = min(height, prev_cow);
        }
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin >> N >> M;
    COW = vector<ll>(N);
    for(int i = 0; i < N; i++){
        cin >> COW[i];
    }
    while(M--){
        eat_candy_cane();
    }
    for(auto &cow : COW){
        cout << cow << "\n";
    }
    return 0;
}