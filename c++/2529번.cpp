#include <bits/stdc++.h>
using namespace std;
#define INF 2100000000

int K;
bool is_used[10];
int ans[10];
char symbol[10];
vector<string> v;

bool is_true(int prev, int cur, int k){ // prev는 k번째 수, cur은 k + 1번째 수
  if(symbol[k] == '>'){
    return prev > cur;
  }
  return prev < cur;
}

// 0번째부터 k번째까지에 수에 대해 주어진 조건을 만족합니다.
// 이전에 쓰인 수는 prev 입니다.
void func(int k, int prev){ 
  if(k == K){ // K + 1 개의 숫자를 고르면 종료한다.
    string tmp = "";
    for(int i = 0; i < K + 1; i++){
      tmp += ((char) ans[i] + '0');
    }
    v.push_back(tmp);
    return;
  }

  for(int i = 0; i < 10; i++){ // i는 새롭게 추가할 수
    if(!is_used[i] and is_true(prev, i, k)){
      ans[k + 1] = i; is_used[i] = true;
      func(k + 1, i);
      ans[k + 1] = 0; is_used[i] = false;
    }
  }

}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> K;
  for(int k = 0; k < K; k++){
    cin >> symbol[k];
  }

  for(int i = 0; i < 10; i++){
    ans[0] = i; is_used[i] = true;
    func(0, i);
    ans[0] = 0; is_used[i] = false;
  }

  sort(v.rbegin(), v.rend());
  cout << v.front() << "\n" << v.back() << "\n";
  return 0;
}