// 2번째 인자의 우선 순위가 더 높다면 true를 리턴하고, 그렇지 않다면 false를 리턴
#include <bits/stdc++.h>
using namespace std;

struct compare{
  bool operator()(int &a, int &b){
    return a > b;
  }
};
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int N; cin >> N;
  long long ans = 0;
  priority_queue<int, vector<int>, compare> pq;
  while(N--){
    int x; cin >> x;
    pq.push(x);
  }
  while(true){
    if(pq.size() == 1){
      cout << ans << "\n";
      break;
    }
    int min_1 = pq.top(); pq.pop();
    int min_2 = pq.top(); pq.pop();
    pq.push(min_1 + min_2);
    ans += min_1 + min_2;
  }
  return 0;
}