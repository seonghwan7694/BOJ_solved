#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  priority_queue<int> pq; // 최대 힙
  int N; cin >> N;
  while(N--){
    int x; cin >> x;
    if(x == 0){
      if(pq.empty()){
        cout << 0 << "\n";
        continue;
      }
      cout << pq.top() << "\n";
      pq.pop();
    }else{
      pq.push(x);
    }
  }

  return 0;
}