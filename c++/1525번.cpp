#include <bits/stdc++.h>
using namespace std;
string ans = "123456780";
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
unordered_set<string> us;

bool chk(string &str){
  for(int i = 0; i < 9; i++){
    if(ans[i] != str[i]){
      return false;
    }
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  string input;
  int i_idx, j_idx;
  for(int i = 0; i < 3; i++){
    char tmp;
    for(int j = 0; j < 3; j++){
      cin >> tmp;
      input.push_back(tmp);
      if(tmp == '0'){
        i_idx = i;
        j_idx = j;
      }
    }
  }
  queue<pair<pair<int, string>, pair<int, int>>> q;
  q.push({{0, input}, {i_idx, j_idx}});

  while(!q.empty()){
    auto cur = q.front(); q.pop();

    int cnt = cur.first.first;
    string str = cur.first.second;
    int x = cur.second.first;
    int y = cur.second.second;

    if(us.find(str) == us.end()){
      us.insert(str);
    }else{
      continue;
    }
    if(chk(str)){
      cout << cnt << "\n";
      return 0;
    }

    for(int dir = 0; dir < 4; dir++){
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if(nx < 0 or nx >= 3 or ny < 0 or ny >= 3) continue;
      swap(str[nx * 3 + ny], str[x * 3 + y]);
      q.push({{cnt + 1, str}, {nx, ny}});
      swap(str[nx * 3 + ny], str[x * 3 + y]);
    }
  }
  /*

  0 1 2 (0, 0) (0, 1) (0, 2)
  3 4 5 (1, 0) (1, 1) (1, 2)
  6 7 8 (2, 0) (2, 1) (2, 2)

  */
  cout << -1 << "\n";
  return 0;
}