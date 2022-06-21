// 멀티셋 이용
#include <bits/stdc++.h>
using namespace std;

int tc, k;

void solution(){
  cin >> k;
  multiset<int> ms;
  while(k--){
    char cmd; int n;
    cin >> cmd >> n;
    if(cmd == 'I'){
      ms.insert(n);
    }else if(cmd == 'D' and !ms.empty()){
      if(n == 1){ // 최댓값 하나만 찾고 -> 삭제
        ms.erase(prev(ms.end()));
      }else if(n == -1){ // 최소값 하나만 찾고 -> 삭제
        ms.erase(ms.begin());
      }
    }
  }

  if(!ms.empty()) cout << *prev(ms.end()) << " " << *ms.begin() << "\n"; // 큰 값, 작은 값 
  else cout << "EMPTY" << "\n";

  return;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> tc;
  while(tc--){
    solution();
  }

  return 0;
}