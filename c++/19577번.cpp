#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX_N 100'000
using namespace std;

vector<long long> v;
long long N, ret;

long long phi(long long n){
    long long res = n;
    for(long long i = 2; i * i <= n; i++){
        if(n % i == 0){
            while(n % i == 0) n /= i;
            res -= res / i;
        }
    }
    if(n > 1) res -= res / n;
    return res;
}

int main(){
    cin >> N;

    for(int i = 2; i <= N; i++){
        ret += phi(i);
    }
    cout << ret << "\n";
    return 0;
}