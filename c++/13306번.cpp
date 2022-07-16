#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX = 200000;
 
// 유니온 파인드
struct UnionFind{
    int uf[MAX];
    UnionFind(){ fill(uf, uf+MAX, -1); }
    int find(int a){
        if(uf[a] < 0) return a;
        return uf[a] = find(uf[a]);
    }
    bool merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return false;
        uf[b] = a;
        return true;
    }
};
 
int main(){
    int N, Q, p[MAX], q[MAX*2][3];
    UnionFind UF;
    scanf("%d %d", &N, &Q);
    Q += N-1;
    for(int i = 1; i < N; ++i){
        scanf("%d", p+i);
        --p[i];
    }
    // 쿼리들을 저장해 둠
    for(int i = 0; i < Q; ++i){
        scanf("%d %d", &q[i][0], &q[i][1]);
        q[i][1]--;
        if(q[i][0] == 1){
            scanf("%d", &q[i][2]);
            q[i][2]--;
        }
    }
 
    // 쿼리들을 거꾸로 풀 것이므로 정답도 스택에 쌓아뒀다가 거꾸로 출력
    stack<bool> result;
    // 쿼리들을 역순으로 본다.
    for(int i = Q-1; i >= 0; --i){
        // (1) 쿼리의 경우 본래 자신의 부모였던 정점과 잇는다.
        if(q[i][0] == 0) UF.merge(q[i][1], p[q[i][1]]);
        // (2) 쿼리의 경우 두 정점이 같은 집합 내에 있는지 본다.
        else{
            int u = UF.find(q[i][1]), v = UF.find(q[i][2]);
            result.push(u == v);
        }
    }
 
    // 결과 출력
    while(!result.empty()){
        puts(result.top() ? "YES" : "NO");
        result.pop();
    }
}