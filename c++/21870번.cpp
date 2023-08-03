#include <bits/stdc++.h>
using namespace std;
#define MAX_N 202020

int N;
int A[MAX_N];
/*

5
1 2 3 4 5

{1, 2}, {3, 4, 5}
1
{3, 4, 5}
3
{4, 5}
4 5


{1, 2}, {3, 4, 5}
1
{1, 2}
1, 2
*/

long long int RES = 0, MAX_RES = 0;

int GCD(int a, int b){
    int c;
    while( b != 0){
        c = a%b; 
        a = b;
        b = c;
    }
    return a;
}

int get_GCDs(int s, int e){
    if(s == e) return A[s];
    int res = A[s];
    for(int i = s + 1; i <= e; i++){
        res = GCD(A[i], res);
    }
    return res;
}

int Divide(int s, int e){
    if(s == e) return A[s];

    int l = s + floor((double)(e - s + 1) / 2.0) - 1, r = e - ceil((double)(e - s + 1) / 2.0) + 1;

    int val1 = get_GCDs(s, l) + Divide(r, e);
    int val2 = get_GCDs(r, e) + Divide(s, l);
    return max(val1, val2);
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    cout << Divide(0, N-1) << "\n";
    return 0;
}