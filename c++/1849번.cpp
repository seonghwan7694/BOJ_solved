#include <iostream>
#include <vector>
#define MAX_SIZE 101010
using namespace std;

// A[i] : i 앞에 있는 수 들 중, i보다 큰 수들의 '개수'
/*
    A[i] = i보다 큰 수 ... i ... i보다 크거나 작거나 상관 X

    A[1] = 5 // {1보다 큰 5개} 1 {2개}
    A[2] = 0  // 2 {1보다 큰 4개} 1 {2개}
    A[3] = 1 // 2 {3보다 큰 1개} {3} {2개} 1 {2개}
    A[4] = 2 // 2 {3보다 큰 1개} {3} {2개} 1 {2개}
    A[5] = 1
    A[6] = 2
    A[7] = 0
    A[8] = 0
*/

int seg[MAX_SIZE * 4];
int ans[MAX_SIZE];

int init(int cur, int s, int e){
    if(s == e) return seg[cur] = 1;
    int m = (s + e) >> 1;
    return seg[cur] = init(cur * 2, s, m) + init(cur * 2 + 1, m + 1, e);
}

void update(int cur, int s, int e, int i, int ai){
    if(s == e){
        seg[cur] = 0;
        ans[s] = i;
        return;
    }
    seg[cur] -= 1;
    int m = (s + e) >> 1;
    if(seg[cur * 2] < ai) update(cur * 2 + 1, m + 1, e, i, ai - seg[cur * 2]);
    else update(cur * 2, s, m, i, ai);
}
int main(){
    int N;
    cin >> N;
    init(1, 1, N);
    for(int i = 1, ai; i <= N; i++){
        cin >> ai;
        update(1, 1, N, i, ai + 1);
    }
    for(int i = 1; i <= N; i++) cout << ans[i] << "\n";
}