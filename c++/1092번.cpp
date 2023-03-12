#include <bits/stdc++.h>
using namespace std;

int N, M, res;
vector<int> crane;
vector<int> box;

int main(){
    ios::sync_with_stdio(false);

    cin >> N;
    for(int i = 0, tmp; i < N; i++){
        cin >> tmp;
        crane.push_back(tmp);
    }
    sort(crane.begin(), crane.end());
    reverse(crane.begin(), crane.end());

    cin >> M;
    for(int i = 0, tmp; i < M; i++){
        cin >> tmp;
        box.push_back(tmp);
    }
    sort(box.begin(), box.end());
    reverse(box.begin(), box.end());


    if(*crane.begin() < *box.begin()){
        cout << -1 << "\n";
        return 0;
    }

    while(!box.empty()){
       res++;
       for(int i = 0; i < crane.size(); i++){
            for(int j = 0; j < box.size(); j++){
                if(crane[i] >= box[j]){
                    box.erase(box.begin() + j);
                    break;
                }
            }
       }
    }
    cout << res << "\n";
    return 0;
}