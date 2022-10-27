#include <bits/stdc++.h>
using namespace std;

int x, y, chk;
pair<int, int> idx;
int board[5][5];
bool vis[5][5];
pair<int, int> um[26];

bool hori[5], vertic[5], diagonal[2];
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      cin >> board[i][j];
      um[board[i][j]] = {i, j};
    }
  }

  queue<int> q;
  for(int i = 0, tmp; i < 25; i++){
    cin >> tmp;
    q.push(tmp);
  }

  for(int cnt = 1; cnt <= 25; cnt++){
    idx = um[q.front()]; q.pop();
    vis[idx.first][idx.second] = true;

    x = idx.first;
    y = 0;
    for(int i = 0; i <= 5; i++){
      if(i == 5){
        if(!hori[x]){
          hori[x] = true;
          chk++;
        }
        break;
      }
      if(!vis[x][y]) break;
      y++;
    }

    x = 0;
    y = idx.second;
    for(int j = 0; j <= 5; j++){
      if(j == 5){
        if(!vertic[y]){
          vertic[y] = true;
          chk++;
        }
        break;
      }
      if(!vis[x][y]) break;
      x++;
    }

    x = 0;
    y = 0;
    for(int k = 0; k <= 5; k++){
      if(k == 5){
        if(!diagonal[0]){
          diagonal[0] = true;
          chk++;
        }
        break;
      }
      if(!vis[x][y]) break;
      x++, y++;
    }

    x = 4;
    y = 0;
    for(int k = 0; k <= 5; k++){
      if(k == 5){
        if(!diagonal[1]){
          diagonal[1] = true;
          chk++;
        }
        break;
      }
      if(!vis[x][y]) break;
      x--, y++;
    }

    if(chk >= 3){
      cout << cnt << "\n";
      break;
    }
  }
  return 0;
}