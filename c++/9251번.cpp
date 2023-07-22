#include <bits/stdc++.h>
using namespace std;
int D[1010][1010];
string A, B;
int main(){
    ios::sync_with_stdio(false);
    cin >> A >> B;
    A = "#" + A;
    B = "#" + B;
    for(int i = 1; i <= A.size() - 1; i++){
        for(int j = 1; j <= B.size() - 1; j++){
            if(A[i] == B[j]) D[i][j] = D[i-1][j-1] + 1;
            else{
                D[i][j] = max(D[i-1][j], D[i][j-1]);
            }
        }
    }
    cout << D[A.size() - 1][B.size() - 1] << "\n";


    return 0;
}