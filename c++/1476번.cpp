#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int e, s, m; cin >> e >> s >> m;
  int e_mod = 15, s_mod = 28, m_mod = 19;
  int e_tmp = 1, s_tmp = 1, m_tmp = 1;
  for(int year = 1; year <= 7980; year++){
    if(e == e_tmp and s == s_tmp and m == m_tmp){
      cout << year;
      return 0;
    }
    if(e_tmp % e_mod == 0) e_tmp = 1;
    else e_tmp++;
    if(s_tmp % s_mod == 0) s_tmp = 1;
    else s_tmp++;
    if(m_tmp % m_mod == 0) m_tmp = 1;
    else m_tmp++;
  }
  return 0;
}