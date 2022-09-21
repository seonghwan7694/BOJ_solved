#include <bits/stdc++.h>
using namespace std;
const int pivot = 125;
const int INF = 987654321;
int N;
string input;
char board[250][250];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int d = 0;
pair<int, int> a(pivot, pivot), b(pivot, pivot), cur(pivot, pivot);

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> input;

  board[cur.first][cur.second] = '.';
  for(auto& c : input){
    if(c == 'R'){
      if(++d == 4) d = 0;
    }else if(c == 'L'){
      if(--d == -1) d = 3;
    }else{
      cur.first += dx[d];
      cur.second += dy[d];
      board[cur.first][cur.second] = '.';
      a = {min(a.first, cur.first), min(a.second, cur.second)};
      b = {max(b.first, cur.first), max(b.second, cur.second)};
    }
  }

  for(int i = a.first; i <= b.first; i++){
    for(int j = a.second; j <= b.second; j++){
      if(board[i][j] == '.') cout << board[i][j];
      else cout << '#';
    }
    cout << "\n";
  }
  return 0;
}