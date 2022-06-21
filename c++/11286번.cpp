#include <bits/stdc++.h>
using namespace std;

struct compare{
  bool operator()(int &a, int &b){
    // 1. 절대값이 작은 것이 우선순위가 높다.
    // 2. 절대값이 같다면, 가장 작은 수가 우선순위가 높다.
    if(abs(a) != abs(b)) return abs(a) > abs(b);
    return a > 0 and b < 0;
  }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int N; cin >> N;
  priority_queue<int, vector<int>, compare> pq;

  while(N--){
    int x; cin >> x;
    if(x != 0){
      pq.push(x);
    }else{
      if(pq.empty()){
        cout << 0 << "\n";
        continue;
      }
      cout << pq.top() << "\n"; pq.pop();
    }
  }


  return 0;
}