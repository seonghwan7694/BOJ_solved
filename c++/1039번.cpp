#include <bits/stdc++.h>
using namespace std;
string n;
int N, K, ans = -1, var, length, I, J, tmp_K;
int pow102[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
vector<bool> chk(1010101, false);
void SWAP(int& num, int i, int j){
  I = (num / pow102[length - i - 1])%10;
  J = (num / pow102[length - j - 1])%10;
  num -= pow102[length - i - 1] * I + pow102[length - j - 1] * J; 
  num += pow102[length - i - 1] * J + pow102[length - j - 1] * I; 
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> K;

  N = (int) stoi(n);
  length = n.length();
  queue<pair<int, int>> q;
  q.push({N, K});
  tmp_K = K;

  while(!q.empty()){
    auto cur = q.front(); q.pop();
    if(cur.second == 0){
      ans = max(ans, cur.first);
      continue;
    }

    if(tmp_K != cur.second){
      fill(chk.begin(), chk.end(), false);
      tmp_K = cur.second;
    }

    for(int i = 0; i < length; i++){
      for(int j = i + 1; j < length; j++){
        if(i == 0 and cur.first / pow102[length - j - 1]%10 == 0) continue;
        SWAP(cur.first, i, j);
        if(chk[cur.first] == false){
          chk[cur.first] = true;
          q.push({cur.first, cur.second - 1});
        }
        SWAP(cur.first, i, j);
      }
    }
  }

  cout << (ans == -1 ? -1 : ans) << "\n";

  return 0;
}