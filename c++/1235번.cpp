#include <bits/stdc++.h>
using namespace std;
#define lld long long int
lld N, k;
vector<string> student;
string tmp;
set<string> s;
int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> tmp;
        student.push_back(tmp);
    }
    for(int i = 1; i <= student[0].length(); i++){
        s.clear();
        for(int j = 0; j <= N; j++){
            if(j == N){
                cout << i << "\n";
                return 0;
            }
            string str = student[j];
            str = str.substr(student[0].length() - i, i);
            if(s.find(str) == s.end()) s.insert(str);
            else break;
        }
    }

    return 0;
}