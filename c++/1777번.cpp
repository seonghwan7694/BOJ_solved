#include <iostream>
#include <vector>
using namespace std;
#define MAX_SIZE 101010

int A[MAX_SIZE], seg[MAX_SIZE * 4], N, ans[MAX_SIZE];

void init(int cur, int s, int e){
    if(s == e){
        seg[cur] = 1; 
        return;
    }
    int m = (s + e) >> 1;
    init(cur * 2, s, m);
    init(cur * 2 + 1, m + 1, e); 
    seg[cur] = seg[cur * 2] + seg[cur * 2 + 1]; // 구간 [s, e]에서 빈 자리 수
    return;
}

void update(int cur, int s, int e, int i, int ai){
    if(s == e){
        seg[cur]--;
        ans[s] = i;
        return;
    }
    int m = (s + e) >> 1;
    // ai의 값에 따라 i를 넣을 위치를 결정하면됨.
    if(seg[cur * 2 + 1] > ai){
        update(cur * 2 + 1, m + 1, e, i, ai);
    }else{
        update(cur * 2, s, m, i, ai - seg[cur * 2 + 1]);
    }
    seg[cur] = seg[cur * 2] + seg[cur * 2 + 1];
    return;
}
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];
    init(1, 1, N);
    for(int ri = N; ri >= 1; ri--) update(1, 1, N, ri, A[ri]);
    for(int i = 1; i <= N; i++) cout << ans[i] << " ";
    cout << "\n";
    return 0;
}