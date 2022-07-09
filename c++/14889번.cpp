#include <bits/stdc++.h>
using namespace std;

int N;
int board[22][22];
vector<int> v;
int res = 987654321;

int get_score(){
  int start_score = 0, link_score = 0;
  vector<int> start_team, link_team;
  for(int i = 0; i < v.size(); i++){
    if(v[i] == 0){
      start_team.push_back(i);
    }else if(v[i] == 1){
      link_team.push_back(i);
    }
  }
  for(int i = 0; i < start_team.size(); i++){
    for(int j = i + 1; j < start_team.size(); j++){
      start_score += board[start_team[i]][start_team[j]] + board[start_team[j]][start_team[i]];
    }
  }
  for(int i = 0; i < link_team.size(); i++){
    for(int j = i + 1; j < link_team.size(); j++){
      link_score += board[link_team[i]][link_team[j]] + board[link_team[j]][link_team[i]];
    }
  }


  return abs(start_score - link_score);
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> board[i][j];
    }
  }

  for(int i = 0; i < N/2; i++){ v.push_back(0); }
  for(int i = 0; i < N/2; i++){ v.push_back(1); }

  do{
    res = min(res, get_score());
    if(res == 0) break;
  }while(next_permutation(v.begin(), v.end()));
  cout << res << "\n";
  return 0;
}