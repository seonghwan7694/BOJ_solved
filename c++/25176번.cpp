#include <iostream>

using namespace std;
int N, ret = 1;

int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++){
        ret *= i;
    }
    cout << ret << "\n";
    return 0;
}