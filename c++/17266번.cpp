#include <bits/stdc++.h>
using namespace std;

int N, M, x;

int main(){
    ios::sync_with_stdio(false);

    cin >> N >> M;
    vector<int> X(M + 1);

    for(int i = 0; i < M; i++){
        cin >> X[i];
    }

    int height = max(X[0], N - X[M - 1]);
    for(int i = 1; i < M - 1;  i++){
        while(X[i] + height < X[i + 1] - height){
            height++;
        }
    }
    cout << height << "\n";
    return 0;
}