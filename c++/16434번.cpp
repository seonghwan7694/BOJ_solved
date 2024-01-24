#include <bits/stdc++.h>
using namespace std;
#define lld long long int
lld N, M;
vector<lld> t, a, h;

bool is_possible(lld val){
    lld p_MaxHP = val, p_CurHP = val, p_atk = M, m_atk, m_CurHP, _p;
    for(int i = 0; i < N; i++){
        if(t[i] == 1){
            m_atk = a[i], m_CurHP = h[i];
            _p = m_CurHP%p_atk == 0 ? m_CurHP/p_atk : m_CurHP/p_atk + 1; // monster attack cnt -> _p
            p_CurHP -= (_p - 1) * m_atk; // while monster is attacked, people is attacked (_p - 1) * m_atk
            if(p_CurHP <= 0) return false; 
        }else{
            p_atk += a[i];
            p_CurHP = min(p_MaxHP, p_CurHP + h[i]);
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> N >> M;
    t = vector<lld>(N, 0);
    a = vector<lld>(N, 0);
    h = vector<lld>(N, 0);

    for(lld i = 0, _t, _a, _h; i < N; i++){
        cin >> _t >> _a >> _h;
        t[i] = _t;
        a[i] = _a;
        h[i] = _h;
    }

    lld st = 0, en = 9e18, mid;
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