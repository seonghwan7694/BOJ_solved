#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int N; cin >> N;
  priority_queue<int, vector<int>, greater<int>> pq; // 최소 힙

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      int x; cin >> x;
      if(pq.empty() or pq.size() < N){
        pq.push(x);
        continue;
      }
      if(x > pq.top() and pq.size() >= N){
        pq.push(x);
        pq.pop();
      }
    }
  }
  cout << pq.top() << "\n"; // N번째 큰 수를 출력
  return 0;
}