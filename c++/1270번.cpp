#include <bits/stdc++.h>
#define lld long long int
using namespace std;

lld t, a, b, c, val, idx;
unordered_map<lld, lld> um;
int main(){
    ios::sync_with_stdio(false);
    
    cin >> t;
    while(t--){

        cin >> a;
        um.clear();
        val = 0;
        idx = 0;

        for(lld i = 0; i < a; i++){
            cin >> b;

            if(um.find(b) == um.end()){
                um[b] = 1;
            }else{
                um[b]++;
            }

            if(um[b] > val){
                idx = b;
                val = um[b];
            }
        }

        if(val > a/2) cout << idx << "\n";
        else cout << "SYJKGW" << "\n";
    }
    return 0;
}