#include <bits/stdc++.h>
using namespace std;

int N;
int f(int a, int b, int t){
    return a * t + b;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    vector<pair<int, int>> v(N);
    for(int i = 0; i < N; i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b){
       auto [a1, a2] = a;
       auto [b1, b2] = b;
       if(a1 == 0) return false;
       if(b1 == 0) return true;
       if(a1 == 0 && b1 == 0){
            return a2 < b2;
       }
       return a2 * b1 < b2 * a1;
    });
    /*
    for(int i = 0; i < N; i++){
        auto [a, b] = v[i];
        cout << a <<  " " << b << "\n";
    }
    */
    long long int x = 0;
    long long int t = 0;
    for(int i = 0; i < N; i++){
        x += v[i].first * t + v[i].second;
        x %= 40000;
        t = x;
    }
    cout << x << "\n";
    return 0;
}