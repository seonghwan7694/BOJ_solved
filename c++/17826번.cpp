#include <bits/stdc++.h>
using namespace std;
vector<int> v(50);
int t;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 0; i < 50; i++){
        cin >> v[i];
    }
    cin >> t;
    int rank;
    for(int i = 0; i < 50; i++){
        if(t == v[i]){
            rank = i;
            break;
        } 
    }
    if(rank <= 4){
        cout << "A+" << "\n";
    }else if(rank <= 14){
        cout << "A0" << "\n";
    }else if(rank <= 29){
        cout << "B+" << "\n";
    }else if(rank <= 34){
        cout << "B0" << "\n";
    }else if(rank <= 44){
        cout << "C+" << "\n";
    }else if(rank <= 47){
        cout << "C0" << "\n";
    }else{
        cout << "F" << "\n";
    }
    return 0;
}