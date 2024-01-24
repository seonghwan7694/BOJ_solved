#include <bits/stdc++.h>
#define INF 1000000001
using namespace std;


int blueray_cnt, lecture_cnt;
vector<long long int> lecture_time;

bool is_possible(long long int size){
    long long int blueray_consume = 0;
    int cnt = 1;

    for(auto iter = lecture_time.begin(); iter != lecture_time.end(); iter++){
        if(blueray_consume + *iter > size){
            cnt++;
            if(*iter > size) return false;
            blueray_consume = *iter;
        }else{
            blueray_consume += *iter;
        }
    }

    if(blueray_cnt >= cnt) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);

    cin >> lecture_cnt >> blueray_cnt;
    for(int i = 0, tmp; i < lecture_cnt; i++){
        cin >> tmp;
        lecture_time.push_back(tmp);
    }

    long long int st = 1, en = INF, mid;
    while(st <= en){
        mid = (st + en)/2;
        if(is_possible(mid)){
            en = mid - 1;
        }else{
            st = mid + 1;
        }
    }
    cout << st << "\n";
    return 0;                                                                                                             
}