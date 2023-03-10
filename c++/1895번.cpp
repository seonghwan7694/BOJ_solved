#include <bits/stdc++.h>
using namespace std;

int R, C, T, res;
int a[50][50];
vector<int> v, mid;

int main(){
    ios::sync_with_stdio(false);
    vector<int> v;
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> a[i][j];
        }
    }

    for(int i = 1; i < R - 1; i++){
        for(int j = 1; j < C - 1; j++){
            v.clear();
            v.push_back(a[i-1][j-1]);
            v.push_back(a[i-1][j]);
            v.push_back(a[i-1][j+1]);
            v.push_back(a[i][j-1]);
            v.push_back(a[i][j]);
            v.push_back(a[i][j+1]);
            v.push_back(a[i+1][j-1]);
            v.push_back(a[i+1][j]);
            v.push_back(a[i+1][j+1]);
       		sort(v.begin(), v.end());
            mid.push_back(v[4]);
        }
    }
    cin >> T;
    for(auto &x : mid){
        x >= T ? res++ : 0;
    }
    cout << res << "\n";
    return 0;
}