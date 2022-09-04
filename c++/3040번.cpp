#include <bits/stdc++.h>
using namespace std;
vector<int> input(9, 0);
int tmp[7];
bool chk[9];
void dfs(int n)
{
  if (n == 7)
  {
    int cal = 0;
    for (int i = 0; i < 7; i++)
      cal += tmp[i];
    if (cal == 100)
    {
      for (int i = 0; i < 7; i++)
        cout << tmp[i] << "\n";
      exit(0);
    }
    return;
  }

  for (int i = 0; i < 9; i++)
  {
    if (!chk[i])
    {
      chk[i] = true;
      tmp[n] = input[i];

      dfs(n + 1);

      tmp[n] = 0;
      chk[i] = false;
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);

  for (int i = 0; i < 9; i++)
  {
    cin >> input[i];
  }
  dfs(0);

  return 0;
}