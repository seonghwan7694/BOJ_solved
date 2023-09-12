#include <bits/stdc++.h>
using namespace std;
int N;
int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    vector<tuple<int, int, int>> v(N);
    for(int i = 0, a, b; i < N; i++){
        cin >> a >> b;
        v[i] = make_tuple(a, b, i + 1);
    }
    sort(v.begin(), v.end(), [](tuple<int, int, int> &a, tuple<int, int, int> &b){
        auto [a1, a2, a3] = a;
        auto [b1, b2, b3] = b;
        double aa = a1 / (double) a2;
        double bb = b1 / (double) b2;
        if(aa == bb) return a3 < b3;
        return aa < bb;
    });
    for(int i = 0; i < N; i++){
        auto [a1, a2, a3] = v[i];
        if(i != N - 1) cout << a3 << " ";
        else cout << a3 << "\n";
    }
    return 0;
}