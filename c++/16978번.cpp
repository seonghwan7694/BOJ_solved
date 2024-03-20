#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define SIZE 101010
ll N, A[SIZE], M, op;

struct Node{
    Node *l, *r;
    ll v;
    Node(){l = r = NULL; v = 0;}
};

void init(Node *node, ll s, ll e){
    if(s == e){
        node->v = A[s];
        return;
    }
    ll m = (s + e) >> 1;
    node->l = new Node(); node->r = new Node();
    init(node->l, s, m); init(node->r, m + 1, e);
    node->v = node->l->v + node->r->v;
    return;
}

void add(Node *prev, Node *now, ll s, ll e, ll x, ll v){
    if(s == e){
        now->v = v;
        return;
    }
    ll m = (s + e) >> 1;
    if(x <= m){
        now->l = new Node(); now->r = prev->r;
        add(prev->l, now->l, s, m, x, v);
    }else{
        now->l = prev->l; now->r = new Node();
        add(prev->r, now->r, m + 1, e, x, v);
    }
    now->v = now->l->v + now->r->v;
    return;
}

ll query(Node *node, ll s, ll e, ll l, ll r){
    if(e < l or r < s) return 0;
    if(l <= s and e <= r){
        return node->v;
    }
    ll m = (s + e) >> 1;
    return query(node->l, s, m, l, r) + query(node->r, m + 1, e, l, r);
}

Node* root[SIZE];
vector<ll> ret;
int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }
    root[0] = new Node();
    init(root[0], 1, N);
    cin >> M;

    ll i, v, k, j, cnt = 1;
    while(M--){
        cin >> op;
        if(op == 1){
            cin >> i >> v;
            root[cnt] = new Node();
            add(root[cnt - 1], root[cnt], 1, N, i, v);
            cnt++;
        }else{
            cin >> k >> i >> j;
            ret.push_back(query(root[k], 1, N, i, j));
        }
    }
    for(auto &x : ret) cout << x << "\n";
    return 0;
}