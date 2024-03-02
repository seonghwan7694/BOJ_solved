#include <bits/stdc++.h>
using namespace std;

int N, val;
vector<int> a;
set<int> s;
bool chk[101010];
vector<bool> is_cycle;

int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    a = vector<int>(N + 1);
    for(int i = 1; i <= N; i++){
        cin >> a[i];
        if(i == a[i]){
            s.insert(i);
            chk[i] = true;
        }else{
            val = i;
        }
    }
    cout << s.size() << "\n";
    if(s.size() == N){
        for(int i = 1; i <= N; i++){
            if(i + 1 > N) cout << 1 << " ";
            else cout << i + 1 << " ";
        }
        cout << "\n";
        return 0;
    }
    for(int i = 1; i <= N; i++){
        if(chk[i] == false){
            cout << a[i] << " ";
        }else{
            cout << val << " ";
        }
    }
    cout << "\n";
    return 0;
}