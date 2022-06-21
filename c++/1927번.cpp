// 2번째 인자의 우선 순위가 더 높다면 true를 리턴하고, 그렇지 않다면 false를 리턴
#include <bits/stdc++.h>
using namespace std;

struct compare{
  bool operator() (int &a, int &b){
    return b < a;
  }
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int n; cin >> n;
  priority_queue<int, vector<int>, compare> pq;
  while(n--){
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