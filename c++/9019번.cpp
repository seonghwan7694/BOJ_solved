#include <bits/stdc++.h>
using namespace std;

int TC, from, to, tmp;
bool rgt[10101];


void solution(){
  fill(rgt, rgt + 10101, false);
  cin >> from >> to;

  queue<pair<int, string>> q;

  q.push({from, ""});
  rgt[from] = true;

  while(!q.empty()){
    auto cur = q.front(); q.pop();
    if(cur.first == to){
      cout << cur.second << "\n";
      return;
    }
    // D
    tmp = 2 * cur.first % 10000;
    if(!rgt[tmp]){
      q.push({tmp, cur.second + 'D'});
      rgt[tmp] = true;
    }
    
    // S
    tmp = (cur.first - 1 == -1 ? 9999 : cur.first - 1);
    if(!rgt[tmp]){
      q.push({tmp, cur.second + 'S'});
      rgt[tmp] = true;
    }

    // L
    tmp = (cur.first * 10) % 10000 + cur.first/1000;
    if(!rgt[tmp]){
      q.push({tmp, cur.second + 'L'});
      rgt[tmp] = true;
    }
    // R
    tmp = cur.first/10 + (cur.first % 10) * 1000;
    if(!rgt[tmp]){
      q.push({tmp, cur.second + 'R'});
      rgt[tmp] = true;
    }
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> TC;
  while(TC--){
    solution();
  }


  return 0;
}