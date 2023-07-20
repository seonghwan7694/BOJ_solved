#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100'000'000

int a, b;

bool isPalindrome(int n) {
    string front, back, str_n;
    str_n = to_string(n);
    front = str_n;
    reverse(str_n.begin(), str_n.end());
    back = str_n;
    
    if(front == back) return true;
    else return false;
}

bool isPrime(int num) {
    if(num < 2) return false;

    for(int i = 2 ; i <= sqrt(num); i++) {
        if(num % i == 0) return false;
    }

    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> a >> b;
    for(int i = a; i <= b; i++){
        if(isPalindrome(i) and isPrime(i)) cout << i << "\n";
    }
    cout << "-1" << "\n";
    return 0;
}