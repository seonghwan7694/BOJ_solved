#include <bits/stdc++.h>
using namespace std;

int N, M, D, res;
int board[20][20];
int copy_board[20][20];
bool vis[20][20];
int dx[3] = {0, -1, 0};
int dy[3] = {-1, 0, 1};

pair<int, int> BFS(pair<int, int> Arrow)
{
  queue<pair<int, int>> q;
  memset(vis, 0, sizeof vis);
  vis[Arrow.first][Arrow.second] = true;
  q.push(Arrow);

  while (!q.empty())
  {
    auto cur = q.front();
    q.pop();
    if (board[cur.first][cur.second] == 1)
      return {cur.first, cur.second};
    for (int dir = 0; dir < 3; dir++)
    {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];
      if (nx < 0 or nx >= N or ny < 0 or ny >= M)
        continue;
      if (vis[nx][ny] or (abs(Arrow.first - nx) + abs(Arrow.second - ny)) > D)
        continue;
      vis[nx][ny] = true;
      q.push({nx, ny});
    }
  }
  return {-1, -1};
}

bool enemy_move()
{
  bool flag = true;
  for (int i = N - 1; i >= 0; i--)
  {
    for (int j = 0; j < M; j++)
    {
      if (i == N - 1 and board[i][j] == 1)
      {
        board[i][j] = 0;
      }
      else if (board[i][j] == 1)
      {
        flag = false;
        board[i][j] = 0;
        board[i + 1][j] = 1;
      }
    }
  }
  return flag;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M >> D;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      cin >> board[i][j];
      copy_board[i][j] = board[i][j];
    }
  }

  vector<int> Arrow(M, 0);
  for (int i = M - 3; i < M; i++)
  {
    Arrow[i] = 1;
  }

  do
  {
    int tmp_res = 0;
    vector<int> tmp;
    for (int i = 0; i < M; i++)
    {
      if (Arrow[i])
        tmp.push_back(i);
    }
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < M; j++)
      {
        board[i][j] = copy_board[i][j];
      }
    }
    while (true)
    {
      auto a = BFS({N, tmp[0]});
      auto b = BFS({N, tmp[1]});
      auto c = BFS({N, tmp[2]});
      if (a.first != -1 and a.second != -1 and board[a.first][a.second] == 1)
      {
        board[a.first][a.second] = 0;
        tmp_res++;
      }
      if (b.first != -1 and b.second != -1 and board[b.first][b.second] == 1)
      {
        board[b.first][b.second] = 0;
        tmp_res++;
      }
      if (c.first != -1 and c.second != -1 and board[c.first][c.second] == 1)
      {
        board[c.first][c.second] = 0;
        tmp_res++;
      }
      if (enemy_move())
        break;
    }
    res = max(tmp_res, res);
  } while (next_permutation(Arrow.begin(), Arrow.end()));
  cout << res << "\n";
  return 0;
}