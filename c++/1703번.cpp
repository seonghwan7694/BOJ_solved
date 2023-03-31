#include <bits/stdc++.h>
#include <pthread.h>
using namespace std;

int age, spitting_factor, cut_branch, ans;

int main(){
    ios::sync_with_stdio(false);
    while(true){
        cin >> age;
        if(!age) break;
        ans = 1;
        for(int i = 0; i < age; i++){
            cin >> spitting_factor >> cut_branch;
            ans = ans * spitting_factor - cut_branch;
        }
        cout << ans << endl;
    }

    return 0;
}