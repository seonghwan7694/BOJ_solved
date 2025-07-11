#include <iostream>
#include <vector>
using namespace std;

int a11, a12, a13;
int a21, a22, a23;
int a31, a32, a33;
int val;
bool is_not_zero(int a, int b, int c){
    if(a == 0 or b == 0 or c == 0) return false;
    return true;
}

int determine(){
    if(is_not_zero(a11, a12, a13)) return a11 + a12 + a13;
    if(is_not_zero(a21, a22, a23)) return a21 + a22 + a23;
    if(is_not_zero(a31, a32, a33)) return a31 + a32 + a33;

    if(is_not_zero(a11, a21, a31)) return a11 + a21 + a31;
    if(is_not_zero(a12, a22, a32)) return a12 + a22 + a32;
    if(is_not_zero(a13, a23, a33)) return a13 + a23 + a33;


    if(is_not_zero(a11, a22, a33)) return a11 + a22 + a33;
    if(is_not_zero(a13, a22, a31)) return a13 + a22 + a31;
    
    return -1;
}

int count_zero(int a, int b, int c){
    int res = 0;
    if(a == 0) res++;
    if(b == 0) res++;
    if(c == 0) res++;
    return res;
}

void make(){
    if(count_zero(a11, a12, a13) == 1){
        if(a11 == 0) a11 = val - a12 - a13;
        if(a12 == 0) a12 = val - a11 - a13;
        if(a13 == 0) a13 = val - a12 - a11;
    }
    if(count_zero(a21, a22, a23) == 1){
        if(a21 == 0) a21 = val - a22 - a23;
        if(a22 == 0) a22 = val - a21 - a23;
        if(a23 == 0) a23 = val - a22 - a21;
    }
    if(count_zero(a31, a32, a33) == 1){
        if(a31 == 0) a31 = val - a32 - a33;
        if(a32 == 0) a32 = val - a31 - a33;
        if(a33 == 0) a33 = val - a32 - a31;
    }
    if(count_zero(a11, a21, a31) == 1){
        if(a11 == 0) a11 = val - a21 - a31;
        if(a21 == 0) a21 = val - a11 - a31;
        if(a31 == 0) a31 = val - a11 - a21;
    }
    if(count_zero(a12, a22, a32) == 1){
        if(a12 == 0) a12 = val - a22 - a32;
        if(a22 == 0) a22 = val - a12 - a32;
        if(a32 == 0) a32 = val - a12 - a22;
    }
    if(count_zero(a13, a23, a33) == 1){
        if(a13 == 0) a13 = val - a23 - a33;
        if(a23 == 0) a23 = val - a13 - a33;
        if(a33 == 0) a33 = val - a13 - a23;
    }
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin >> a11 >> a12 >> a13;
    cin >> a21 >> a22 >> a23;
    cin >> a31 >> a32 >> a33;
    if((a11 == 0 and a22 == 0 and a33 == 0)){
        vector<int> v;
        v.push_back(a12 + a13);
        v.push_back(a21 + a23);
        v.push_back(a31 + a32);
        int tmp = v[0] - v[1] + v[0] - v[2];
        tmp = v[0] - tmp;
        a11 = tmp / 2;
        a22 = a11 + v[0] - v[1];
        a33 = a11 + v[0] - v[2];
    }
    if((a13 == 0 and a22 == 0 and a31 == 0)){
        vector<int> v;
        v.push_back(a11 + a12);
        v.push_back(a21 + a23);
        v.push_back(a32 + a33);
        int tmp = v[0] - v[1] + v[0] - v[2];
        tmp = v[0] - tmp;
        a13 = tmp / 2;
        a22 = a13 + v[0] - v[1];
        a31 = a13 + v[0] - v[2];
    }
    while(true){
        val = determine();
        if(val != -1) break;
    }
    while (true) {
        int prev = a11 + a12 + a13 + a21 + a22 + a23 + a31 + a32 + a33;
        make();
        int now = a11 + a12 + a13 + a21 + a22 + a23 + a31 + a32 + a33;
        if (prev == now) break;
    }
    cout << a11 << " " << a12 << " " << a13 << "\n";
    cout << a21 << " " << a22 << " " << a23 << "\n";
    cout << a31 << " " << a32 << " " << a33 << "\n";
    return 0;
}