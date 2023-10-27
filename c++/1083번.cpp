#include <algorithm>
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
    int idx = 0;
    while(S > 0){
        if(idx == N) break;
        vector<int>::iterator max_iter = max_element(A.begin() + idx, (A.begin() + idx + S + 1 > A.end()) ? A.end() : A.begin() + idx + S + 1);
        if(max_iter == A.begin() + idx){
            idx++;
            continue;
        }
        int max_val = *max_iter;
        S -= max_iter - (A.begin() + idx);
        A.erase(max_iter);
        A.insert(A.begin() + idx, max_val);
        idx++;
    }
    for(auto &x : A) cout << x << " ";
    cout << "\n";
    return 0;
}