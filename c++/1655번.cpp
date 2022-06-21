#include <bits/stdc++.h>
using namespace std;

int N;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  // 1. 백준이가 정수를 하나씩 외칠때마다 동생은 지금까지 백준이가 말한 수 중에서 중간값을 말해야 한다.
  // 2. 만약, 그동안 백준이가 외친 수의 개수가 짝수개라면 중간에 있는 두 수 중에서 작은 수를 말해야 한다.


  // 중간값을 O(1)에 찾을 수 있어야함. 그래야 시간초과가 발생하지 않을 듯 함.


  cin >> N;
  priority_queue<int, vector<int>, greater<int>> min_h; // 최소 힙
  priority_queue<int> max_h; // 최대 힙

  for(int i = 1, x; i <= N; i++){
    cin >> x;
    
    if(min_h.size() >= max_h.size()){
      max_h.push(x);
    }else{
      min_h.push(x);
    }

    if(max_h.size() != 0 and min_h.size() != 0){
      if(max_h.top() > min_h.top()){
        int tmp1 = max_h.top();
        int tmp2 = min_h.top();
        max_h.pop();
        min_h.pop();
        max_h.push(tmp2);
        min_h.push(tmp1);
      }
    }


    cout << max_h.top() << "\n";
  }
  return 0;
}