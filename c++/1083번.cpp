#include <bits/stdc++.h>
using namespace std;

int N, S;

int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    vector<int> A(N, 0);
    for(int i = 0, tmp; i < N; i++){
        cin >> A[i];
    }
    cin >> S;

    for(int i = 0; i < N; i++){
        for(int j = i + 1, k = i; j < N; j++, k++){
            if(A[k] < A[j]){
                swap(A[k], A[j]);
                if(--S == 0){
                    for(auto &x : A) cout << x << " ";
                    cout << "\n";
                    return 0;
                }
            }
        }
    }
    for(auto &x : A) cout << x << " ";
    cout << "\n";
    return 0;
}