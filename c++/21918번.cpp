#include <bits/stdc++.h>
using namespace std;

int N, M;
bool bulb[4040];

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 1, s; i <= N; i++){
        cin >> bulb[i];
    }

    int a, b, c;
    while(M--){
        cin >> a >> b >> c;
        if(a == 1){
            bulb[b] = c;
        }else if(a == 2){
            for(int i = b; i <= c; i++){
                bulb[i] = !bulb[i];
            }
        }else if(a == 3){
            for(int i = b; i <= c; i++){
                bulb[i] = 0;
            }
        }else{
            for(int i = b; i <= c; i++){
                bulb[i] = 1;
            }
        }
    }
    for(int i = 1; i <= N; i++) cout << bulb[i] << " ";
    cout << "\n";
    return 0;
}