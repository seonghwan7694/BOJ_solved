#include <bits/stdc++.h>
using namespace std;
#define lld long long int
lld N, C; // under C
map<lld, lld> number; // val -> idx
map<lld, lld> order; // idx -> val

int main(){
    ios::sync_with_stdio(false);

    cin >> N >> C;
    for(lld i = 0, tmp; i < N; i++){
        cin >> tmp;
        if(order.find(tmp) == order.end()){
            order[tmp] = i;
            number[tmp] = 1;
        }else{
            number[tmp]++;
        }
    }

    vector<pair<lld, lld>> v(number.begin(), number.end());
    sort(v.begin(), v.end(), [](pair<lld, lld> &a, pair<lld, lld> &b){
        if(number[a.first] == number[b.first]){
            return order[a.first] < order[b.first];
        }
        return number[a.first] > number[b.first];

    });
    for(auto &x : v){
        while(x.second--){
            cout << x.first << " ";
        }
    }
    cout << "\n";
    return 0;
}