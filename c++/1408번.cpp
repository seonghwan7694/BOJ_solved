#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int a, b, c, d, e, f;
    scanf("%d:%d:%d", &a, &b, &c);
    scanf("%d:%d:%d", &d, &e, &f);
    int res = (d-a)*3600 + (e-b)*60 + (f-c);
    if(res < 0) res = 24 * 3600 + res;
    printf("%02d:%02d:%02d\n", res/3600, res/60 - res/3600*60, res - (res/3600)*3600 - (res/60 - res/3600*60)*60);
    return 0;
}