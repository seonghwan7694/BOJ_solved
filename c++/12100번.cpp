#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll ans;

// 오른쪽 이동
vector<vector<ll>> right(vector<vector<ll>> board)
{
    vector<vector<bool>> check(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            if (board[i][j] == 0)
                continue;
            for (int k = j + 1; k < n; k++)
            {
                if (board[i][k] == board[i][k - 1] && !check[i][k])
                {
                    board[i][k] *= 2;
                    board[i][k - 1] = 0;
                    check[i][k] = true;
                    break;
                }
                else if (board[i][k] == 0)
                {
                    board[i][k] = board[i][k - 1];
                    board[i][k - 1] = 0;
                }
                else
                {
                    break;
                }
            }
        }
    }
    return board;
}

// 왼쪽 이동
vector<vector<ll>> left(vector<vector<ll>> board)
{
  vector<vector<bool>> check(n, vector<bool>(n, false));

  for (int i = 0; i < n; i++)
  {
      for (int j = 1; j < n; j++)
      {
          if (board[i][j] == 0)
              continue;
          for (int k = j - 1; k >= 0; k--)
          {
              if (board[i][k] == board[i][k + 1] && !check[i][k])
              {
                  board[i][k] *= 2;
                  board[i][k + 1] = 0;
                  check[i][k] = true;
                  break;
              }
              else if (board[i][k] == 0)
              {
                  board[i][k] = board[i][k + 1];
                  board[i][k + 1] = 0;
              }
              else
              {
                  break;
              }
          }
      }
  }
  return board;
}

// 아래 이동
vector<vector<ll>> down(vector<vector<ll>> board)
{
  vector<vector<bool>> check(n, vector<bool>(n, false));

  for (int i = 0; i < n; i++)
  {
      for (int j = n - 2; j >= 0; j--)
      {
          if (board[j][i] == 0)
              continue;
          for (int k = j + 1; k < n; k++)
          {
              if (board[k][i] == board[k - 1][i] && !check[k][i])
              {
                  board[k][i] *= 2;
                  board[k - 1][i] = 0;
                  check[k][i] = true;
                  break;
              }
              else if (board[k][i] == 0)
              {
                  board[k][i] = board[k - 1][i];
                  board[k - 1][i] = 0;
              }
              else
              {
                  break;
              }
          }
      }
  }
  return board;
}

// 위로 이동
vector<vector<ll>> up(vector<vector<ll>> board)
{
  vector<vector<bool>> check(n, vector<bool>(n, false));

  for (int i = 0; i < n; i++)
  {
      for (int j = 1; j < n; j++)
      {
          if (board[j][i] == 0)
              continue;
          for (int k = j - 1; k >= 0; k--)
          {
              if (board[k][i] == board[k + 1][i] && !check[k][i])
              {
                  board[k][i] *= 2;
                  board[k + 1][i] = 0;
                  check[k][i] = true;
                  break;
              }
              else if (board[k][i] == 0)
              {
                  board[k][i] = board[k + 1][i];
                  board[k + 1][i] = 0;
              }
              else
              {
                  break;
              }
          }
      }
  }
  return board;
}

void getMAX(vector<vector<ll>> board){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      ans = max(ans, board[i][j]);
    }
  }
}

void func(int k, vector<vector<ll>> board){
  getMAX(board);
  if(k == 5) return;
  
  func(k + 1, up(board));
  func(k + 1, down(board));
  func(k + 1, left(board));
  func(k + 1, right(board));
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  vector<vector<ll>> board(n, vector<ll>(n));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> board[i][j];
    }
  }
  func(0, board);
  cout << ans << "\n";
  return 0;
}