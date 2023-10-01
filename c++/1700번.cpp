#include <bits/stdc++.h>
using namespace std;

int N, K, ANS;
vector<int> schedule;
vector<int> multitap;

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> K;
    schedule.resize(K);
    for(int i = 0; i < K; i++){
        cin >> schedule[i];
    }
    int idx = 0;
    while(multitap.size() != N){
        if(idx == K){
            cout << 0 << "\n";
            return 0;
        }
        if(find(multitap.begin(), multitap.end(), schedule[idx]) == multitap.end()){
            multitap.push_back(schedule[idx]);
        }
        idx++;
    }

    while(idx != K){
        if(find(multitap.begin(), multitap.end(), schedule[idx]) != multitap.end()){
            idx++;
            continue;
        }

        //가장 나중에 다시 사용되거나 앞으로 사용되지 않는 기기 찾는다.
        map<int, int> cnt;
        vector<int> arr(101, 987654321);

        for(int i = idx + 1; i < K; i++){
            arr[schedule[i]] = min(arr[schedule[i]], i);
        }
        
        multitap.erase(find(multitap.begin(), multitap.end(), off the plug));
        multitap.push_back(schedule[idx]);
        
        idx++;
        ANS++;
    }

    cout << ANS << "\n";
    return 0;
}