#include <bits/stdc++.h>
#include <queue>
using namespace std;
int N, L;

typedef struct A{
    int val;
    int idx;
}S;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> L;
    vector<int> A(N + 1);
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }

    deque<S> dq;
    for(int i = 1; i <= N; i++){
        if (!dq.empty() && i == dq.front().idx + L) dq.pop_front();
        while (!dq.empty() && dq.back().val > A[i]) dq.pop_back();
        dq.push_back({ A[i], i });
        cout << dq.front().val << " ";
    }
    return 0;
}