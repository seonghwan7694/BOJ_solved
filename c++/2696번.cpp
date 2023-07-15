#include <bits/stdc++.h>
#include <queue>
using namespace std;

int T;

void solve(){
    int M;
    cin >> M;
    int MID;
    vector<int> ans;
    priority_queue<int> pq1; // ㄴ내낼내리림ㅊ차찻차수순
    priority_queue<int, vector<int>, greater<int>> pq2; // ㅇ오올오르름ㅊ차찻차수순
    for(int i = 1, tmp; i <= M; i++){
        cin >> tmp;
        if(i == 1){
            MID = tmp;
            // ans.push_back(MID);
            // continue;
        }else{
            if(MID > tmp) pq1.push(tmp);
            else pq2.push(tmp);
        }

        if(i % 2 == 1){
            while(pq1.size() < pq2.size()){
                pq1.push(MID);
                MID = pq2.top();
                pq2.pop();
            }
            while(pq1.size() > pq2.size()){
                pq2.push(MID);
                MID = pq1.top();
                pq1.pop();
            }
            ans.push_back(MID);
        }
    }
    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++){
        if(i != 0 and i % 10 == 0){
            cout << "\n";
        }
        cout << ans[i] << " ";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--){
        solve();
        cout << "\n";
    }

    return 0;
}