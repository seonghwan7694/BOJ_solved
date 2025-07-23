#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define MAX_N 1010101
using namespace std;

int A[MAX_N], F[MAX_N], N, NGF[MAX_N];

// A : 1 1 2 3 4 2 1
// F : 3 3 2 1 1 2 3
int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> A[i];
        F[A[i]]++;
    }

    stack<int> s;
    for(int i = N; i >= 1; i--){
        while(!s.empty() && F[A[i]] >= F[s.top()]){
            s.pop();
        }
        if(s.empty()) NGF[i] = -1;
        else NGF[i] = s.top();
        s.push(A[i]);
    }
    for(int i = 1; i <= N; i++) cout << NGF[i] << " ";
    cout << "\n";
    return 0;
}