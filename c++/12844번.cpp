#include <bits/stdc++.h>
#define SIZE 505050
using namespace std;

int N, M, O, S, T, K, lazy[SIZE * 4], tree[SIZE * 4], arr[SIZE];

void init(int node, int start, int end){
    if(start == end){
        tree[node] = arr[start];
        return;
    }
    int mid = (start + end)/2;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);
    tree[node] =  tree[node * 2] ^ tree[node * 2 + 1];
    return;
}

void update_lazy(int node, int start, int end){
    if(lazy[node] != 0){ //업데이트를 해야 할 경우
        if((end - start + 1) % 2 == 1) tree[node] ^= lazy[node];
        if(start != end){ //리프 노드가 아니면
            lazy[node*2] ^= lazy[node];
            lazy[node*2+1] ^= lazy[node];
        }
        lazy[node] = 0; //업데이트 완료
    }
}

void update_range(int node, int start, int end, int left, int right, int diff){
    update_lazy(node, start, end); //lazy값이 남아있으면 갱신

    if(left>end || right<start){ //범위 초과
        return;
    }
    if(left<=start && end<=right){ //범위 포함
        lazy[node] ^= diff;
        update_lazy(node, start, end); //lazy값이 남아있으면 갱신
        return;
    }
    update_range(node*2, start, (start+end)/2, left, right, diff);
    update_range(node*2+1, (start+end)/2+1, end, left, right, diff);
    tree[node] = tree[node*2] ^ tree[node*2+1];
}

int sum(int node, int start, int end, int left, int right){
   update_lazy(node, start, end); 
   if(left > end or right < start) return 0; 
   if(left <= start and end <= right) return tree[node];
   int mid = (start + end)/2;
   int res1 = sum(node * 2, start, mid, left, right);
   int res2 = sum(node * 2 + 1, mid + 1, end, left, right);
   return res1 ^ res2;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    init(1, 1, N);

    cin >> M;
    vector<int> ans;
    while(M--){
        cin >> O >> S >> T;
        S++, T++;
        if(O == 1){
            cin >> K;
            update_range(1, 1, N, S, T, K);
        }else{
            ans.push_back(sum(1, 1, N, S, T));
        }
    }
    for(auto &x : ans) cout << x << "\n";
    return 0;
}