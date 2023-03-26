#include <bits/stdc++.h>
#define lld long long int
using namespace std;

lld N, hacker;
/*
5
2 -> 1 -> 1
3 -> 2 -> 2
4 -> 3 -> 3
6 -> 5 -> 5
7 -> 6 -> 0
*/

/*
3
5 -> 1
7 -> 2
9 -> 0
*/

/*
4
2 -> 1
2 -> 2
4 -> 3
4 -> 0
*/

/*
5
1 -> 0
2 -> 1 -> 0
3 -> 2 -> 1
4 -> 3 -> 2
5 -> 4 -> 3
*/

/*
6
1 -> 0
1 -> 0
3 -> 2 -> 1
4 -> 3 -> 2
5 -> 4 -> 3
5 -> 4 -> 3
*/

/*
2
1 -> 1 -> 0
4 -> 2 -> 1 -> 0
ans : 2
*/

/*
4
1 -> 0 -> 0
1 -> 0 -> 0
4 -> 3 -> 1
4 -> 3 -> 2
abs : 1
*/
lld defile(vector<lld>& A){

    for(lld i = 0, val = 1; i < A.size(); i++){
        if(A[i] - val >= 0){
            hacker += A[i] - val;
            val++;
        }
    }
    return hacker;
}

int main(){
    cin >> N; 
    vector<lld> A(N, 0);
    for(lld i = 0; i < N; i++){
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    cout << defile(A) << "\n";
    return 0;
}