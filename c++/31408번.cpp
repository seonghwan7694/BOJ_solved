#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int N;
int arr[101010];
int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0, tmp; i < N; i++){
        cin >> tmp;
        arr[tmp]++;
    }
    auto max_val = max_element(arr, arr + 101010);
    int cnt = 0;
    for(int i = 0; i < 101010; i++){
        if(arr + i != max_val){
            cnt += arr[i];
        }
    }
    if(cnt + 1>= *max_val){
        cout << "YES" << "\n";
    }else{
        cout << "NO" << "\n";
    }
    return 0;
}