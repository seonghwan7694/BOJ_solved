#include <bits/stdc++.h>
using namespace std;

vector<int> ans(8);
bool vis[10][10][10][10][10][10][10][10];

bool check(vector<int>& v){
  for(int i = 0; i < 8; i++){
    if(v[i] != ans[i]){
      return false;
    }
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  vector<int> v(8);
  for(int i = 0, t; i < 8; i++){
    cin >> ans[i];
    v[i] = i + 1;
  }
  queue<pair<int, vector<int>>> q;
  q.push({0, v});
  vector<int> vec(8);
  while(true){
    auto cur = q.front(); q.pop();
    if(vis[cur.second[0]][cur.second[1]][cur.second[2]][cur.second[3]][cur.second[4]][cur.second[5]][cur.second[6]][cur.second[7]]){
      continue;
    }else{
      vis[cur.second[0]][cur.second[1]][cur.second[2]][cur.second[3]][cur.second[4]][cur.second[5]][cur.second[6]][cur.second[7]] = true;
    }
    for(int i = 0; i < 8; i++){ vec[i] = cur.second[i]; }
    if(check(vec)){
      cout << cur.first << "\n";
      break;
    }

    // A
    for(int i = 0; i < 8; i++){ vec[i] = cur.second[i]; }
    for(int i = 0; i < 4; i++){ swap(vec[i], vec[7-i]); }
    q.push({cur.first + 1, vec});

    // B
    for(int i = 0; i < 8; i++){ vec[i] = cur.second[i]; }
    // 1 2 3 4
    swap(vec[0], vec[3]); // 4 2 3 1
    swap(vec[1], vec[3]); // 4 1 3 2
    swap(vec[2], vec[3]); // 4 1 2 3

    // 5 6 7 8
    swap(vec[4], vec[5]); // 6 5 7 8 
    swap(vec[5], vec[6]); // 6 7 5 8
    swap(vec[6], vec[7]); // 6 7 8 5
    q.push({cur.first + 1, vec});



    // C
    for(int i = 0; i < 8; i++){ vec[i] = cur.second[i]; }
    // 1 2 3 4 5 6 7 8
    swap(vec[1], vec[2]); // 1 3 2 4 5 6 7 8
    swap(vec[5], vec[6]); // 1 3 2 4 5 7 6 8
    swap(vec[2], vec[6]); // 1 3 6 4 5 7 2 8
    q.push({cur.first + 1, vec});



    // D
    for(int i = 0; i < 8; i++){ vec[i] = cur.second[i]; }
    swap(vec[0], vec[4]);
    q.push({cur.first + 1, vec});
    
  }


  return 0;
}