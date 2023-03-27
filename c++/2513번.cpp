#include <bits/stdc++.h>
#define lld long long int
using namespace std;
lld N, K, S; // N : apartment, K : max people in bus, S : location of school
vector<pair<lld, lld>> L, R;

lld func(vector<pair<lld, lld>> &D){
    lld cost = 0;
    sort(D.begin(), D.end(), [](const pair<lld, lld> &p1, const pair<lld, lld> &p2){
        return p1.first > p2.first; // descending about distance 
    });

    lld k = 0;
    while(!D.empty()){ // take bus 
        // take bus : 0 -> less or equal than K

        // far student has high  priority
        cost += D.front().first * 2; 
        k = 0;

        while(true){ // take bus until full
            if(D.empty()) break;

            auto cur = D.front();
            if(cur.second + k < K){
                k += cur.second;
                D.erase(D.begin());
            }else if(cur.second + k == K){
                D.erase(D.begin());
                break;
            }else if(cur.second + k > K){ // overflow student
                D[0] = {cur.first, cur.second - (K - k)};
                break;
            }
        }
    }
    return cost;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> K >> S;
    for(lld i = 0, loc, stu; i < N; i++){
        cin >> loc >> stu;
        if(loc < S) L.push_back({S - loc, stu}); // 0-based 
        else if(loc > S) R.push_back({loc - S, stu}); // 0-based
    }

    // far student -> high priority
    cout << func(L) + func(R) << "\n";
    return 0;
}