#include <bits/stdc++.h>
using namespace std;

int N;
int arr[4] = {1, 3, 2, 4};
int tarr[4] = {1, 2, 4, 3};

// N = 6, 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    int tmp_N = N;
    cout << "YES" << "\n";
    if(N % 4 == 2){
        for(int i = 0; i < N; i++){
            cout << tarr[i%4] + 4 * (i/4) << " ";
        }
    }else{
        for(int i = 0; i < N; i++){
            cout << arr[i%4] + 4 * (i/4) << " ";
        }
    }
    cout << "\n";
    return 0;
}