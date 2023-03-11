#include <bits/stdc++.h>
using namespace std;

int N, M, tmp, res;
unordered_set<int> us;

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> M;
    auto iter = us.begin();
    while(N--){
        cin >> tmp;
        if((iter = us.find(M - tmp)) == us.end()) us.insert(tmp);
        else us.erase(iter), res++;
    }
    cout << res << "\n";
    return 0;
}