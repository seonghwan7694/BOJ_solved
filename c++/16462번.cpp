#include <iostream>
#include <string>
#include <cmath>
using namespace std;

unsigned long long N, ret;

int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    string str;
    for(int i = 0; i < N; i++){
        cin >> str;
        for(auto &c : str){
            if(c == '0' or c == '6') c = '9';
        }
        ret += (stoi(str) >= 100 ? 100 : stoi(str));
    }
    cout << round((double)ret / N) << "\n";
    return 0;
}