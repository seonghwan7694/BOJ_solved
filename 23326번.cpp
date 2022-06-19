#include <bits/stdc++.h>
using namespace std;

int N, Q, q, tmp, curr = 1;


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> Q;
  set<int> s; // 홍익대학교의 명소의 인덱스를 저장한다.
  for(int i = 1; i <= N; i++){ // 1-indexed
    cin >> tmp;
    if(tmp) s.insert(i);
  }

  auto iter = s.begin();

  while(Q--){
    cin >> q;
    if(q == 1){
      cin >> tmp;
      if((iter = s.find(tmp)) == s.end()) s.insert(tmp); // 명소가 아니라면, 명소로 추가
      else s.erase(iter); // 명소이면, 명소를 삭제
    }else if(q == 2){
      cin >> tmp;
      curr = (curr + tmp - 1)%N + 1; // 원형
    }else if(q == 3){
      if(s.empty()){
        cout << -1 << "\n";
        continue;
      }
      iter = s.lower_bound(curr);
      if(iter != s.end()){
        cout << *iter - curr << "\n";
      }else{
        cout << N - curr + *s.begin() << "\n";
      }
    }
  }
  return 0;
}