#include <bits/stdc++.h>
using namespace std;
int n, m, col_ans, row_ans;
string tmp[50];
bool column[50], row[50];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> tmp[i];
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(tmp[i][j] == 'X'){
        column[i] = true;
        row[j] = true;
      }
    }
  }
  for(int i = 0; i < n; i++){
    if(!column[i]) col_ans++;
  }
  for(int i = 0; i < m; i++){
    if(!row[i]) row_ans++;
  }

  cout << min(col_ans, row_ans) + abs(col_ans - row_ans) << "\n";
  return 0;
}