#include <bits/stdc++.h>
using namespace std;


bool visited[3030][3030]; // {현재 이모티콘 개수, 현재 클립보드에 저장된 이모티콘 개수}
int S;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> S;

  // {현재 이모티콘 개수, 현재 클립보드에 저장된 이모티콘 개수, 현재 시간}
  queue<tuple<int, int, int>> q;

  q.push({1, 0, 0});
  visited[1][0] = true;

  while(!q.empty()){
    auto cur = q.front(); q.pop();
    int cur_emo = get<0>(cur);
    int cur_clip = get<1>(cur);
    int cur_time = get<2>(cur);

    if(cur_emo == S){
      cout << cur_time << "\n";
      return 0;
    }
    // 1. 화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장한다.
    if(cur_clip + cur_emo < 2020 and !visited[cur_emo][cur_clip + cur_emo]){
      q.push({cur_emo, cur_emo, cur_time + 1});
    }

    // 2. 클립보드에 있는 이모티콘을 화면에 붙여넣기 한다.
    if(cur_clip + cur_emo < 2020 and cur_clip != 0 and !visited[cur_emo + cur_clip][cur_clip]){
      q.push({cur_emo + cur_clip, cur_clip, cur_time + 1});
      visited[cur_emo + cur_clip][cur_clip] = true;
    }


    // 3. 화면에 있는 이모티콘 중 하나를 삭제한다.
    if(cur_emo - 1 >= 0 and !visited[cur_emo - 1][cur_clip]){
      q.push({cur_emo - 1, cur_clip, cur_time + 1});
      visited[cur_emo - 1][cur_clip] = true;
    }
  }
  
  return 0;
}