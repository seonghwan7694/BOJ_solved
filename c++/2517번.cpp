#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll N, res;
vector<ll> arr, tree, line, ans;
map<ll, ll> vti, itv;


void update(int node, int st, int en, int idx, int diff){
    if(idx < st or en < idx) return;
    tree[node] += diff;
    if(st != en){
        update(node * 2, st, (st + en)/2, idx, diff);
        update(node * 2+1, (st + en)/2 + 1, en, idx, diff);
    }
}

long long sum(int idx, int left, int right, int st, int en){ // get sum [left, right]
    if(st > right or en < left) return 0;
    if(left <= st and en <= right) return tree[idx]; // 탐색하는 범위가 포함되는 경우   
    return sum(idx * 2, left, right, st, (st + en)/2) + sum(idx * 2 + 1, left, right, (st + en)/2 + 1, en);

}

int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    arr = vector<ll>(N + 10);
    ans = vector<ll>(N + 10);
    tree = vector<ll>(4*(N + 10));
    for(int i = 1, v; i <= N; i++){
        cin >> v;
        line.push_back(v);
        vti.insert({v, i});
    }

    sort(line.begin(), line.end(), greater<int>());
    for(int i = 1; i <= N; i++){
        int idx = vti[line[i-1]];
        res = sum(1, 1, idx, 1, N) + 1;
        update(1, 1, N, idx, 1);
        ans[idx] = res;
    }
    for(int i = 1; i <= N; i++){
        cout << ans[i] << "\n";
    }
    return 0;
}