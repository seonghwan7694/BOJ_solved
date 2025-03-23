#include <bits/stdc++.h>
using namespace std;

int N, Q, m;
vector<int> A, B;

// O(nlogn) 언더로...

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> Q;

    A.resize(N), B.resize(N);
    for(int i = 0, tmp; i < N; i++){
        cin >> A[i];
    }

    while(Q--){ // Q = 300'000
        cin >> m; // makes A1 to AN -> A mod m -> 0 ~ m - 1
        
    }
    return 0;
}