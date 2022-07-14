#include <bits/stdc++.h>
using namespace std;
int N, idx;
string str;
vector<int> ans;
bool flag;

int get_sign(vector<vector<int>> &S, int i, int j){ // 구간 [i, j]
  int sum = 0;
  for(int x = i; x <= j; x++){
    sum += ans[x];
  }
  if(sum > 0) return 1;
  else if(sum < 0) return -1;
  return 0;
}

void func(vector<vector<int>> &S, int n){ // n개를 골랐다.
  if(flag) return;

  for(int i = 0; i < n; i++){
    for(int j = i; j < n; j++){
      if(S[i][j] != get_sign(S, i, j)) return;
    }
  }

  if(n == N){ // N개를 골랐다.
    for(auto x : ans){
      cout << x << " ";
    }
    flag = true;
    return;
  }
  
  if(S[n][n] == 1){
    for(int i = 1; i <= 10; i++){
      ans.push_back(i);
      func(S, n + 1);
      ans.pop_back();
    }
  }else if(S[n][n] == -1){
    for(int i = -10; i <= -1; i++){
      ans.push_back(i);
      func(S, n + 1);
      ans.pop_back();
    }
  }else{
    ans.push_back(0);
    func(S, n + 1);
    ans.pop_back();
  }
  return;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> N; cin >> str;
  vector<vector<int>>S(N, vector<int>(N));

  for(int i = 0; i < N; i++){
    for(int j = i; j < N; j++){
      if(str[idx] == '+'){
        S[i][j] = 1;
      }else if(str[idx] == '-'){
        S[i][j] = -1;
      }else{
        S[i][j] = 0;
      }
      idx++;
    }
  }
  func(S, 0);
  
  return 0;
}