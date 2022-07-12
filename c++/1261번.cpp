#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[101][101];
bool visited[222][101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<int> ans;
void dfs(int x, int y, int deepth){
  if(deepth > 202) return;
  if(x == N and y == M){
    ans.push_back(deepth);
    return;
  }

  for(int dir = 0; dir < 4; dir++){
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(nx < 1 or nx > N or ny < 1 or ny > M) continue;
    if(board[nx][ny] == 0 and !visited[deepth][nx][ny]){
      visited[deepth][nx][ny] = true; dfs(nx, ny, deepth);
    }else if(board[nx][ny] == 1 and !visited[deepth + 1][nx][ny]){
      visited[deepth + 1][nx][ny] = true; dfs(nx, ny, deepth + 1);
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> M >> N;
  for(int i = 1; i <= N; i++){
    string str; cin >> str;
    for(int j = 1; j <= M; j++){
      board[i][j] = str[j - 1] - '0';
    }
  }
  visited[0][1][1] = true; dfs(1, 1, 0);
  sort(ans.begin(), ans.end());
  cout << ans.front() << "\n";
  return 0;
}