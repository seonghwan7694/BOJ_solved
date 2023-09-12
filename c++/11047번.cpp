#include <bits/stdc++.h>
using namespace std;


int N, K;
int main(){
    ios::sync_with_stdio(false);
    cin >> N >> K;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    sort(A.begin(), A.end(), greater<int>());
    for(int i = 0, tmp = 0, k = 0; i < N; i++){
        while(tmp + A[i] <= K){
            tmp += A[i];
            k++;
        }
        if(tmp == K){
            cout << k << "\n";
            return 0;
        }
    }
    return 0;
}