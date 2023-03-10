#include <bits/stdc++.h>
using namespace std;

long long int N, res;
vector<int> v;

int main(){
    ios::sync_with_stdio(false);
    // 강호에게 원래 주려고 생각했던 돈 - 받은 등수 + 1 만큼의 팁

    cin >> N;

    for(int i = 0, a; i < N; i++){
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end(), [](int &a, int &b){return a > b;});
    for(int i = 1; i <= N; i++){
        res += (v[i - 1] - i + 1 >= 0 ? v[i - 1] - i + 1 : 0);
    }

    cout << res << "\n";

    return 0;
}