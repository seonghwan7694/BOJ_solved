#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define INF (1 << 30)

int n, x, y;
vector<pair<int, int>> v;
set<pair<int, int>> s;

int dist(pair<int, int> a, pair<int, int> b){
  return (a.X - b.X)*(a.X - b.X) + (a.Y - b.Y)*(a.Y - b.Y);
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> x >> y;
    v.push_back({x, y});
  }

  sort(v.begin(), v.end()); // 벡터를 X좌표 순으로 정렬을 한 뒤
  s.insert({v[0].Y, v[0].X});
  s.insert({v[1].Y, v[1].X}); // 첫번째 점과 두 번째 점을 set에 삽입한다.

  int mini = dist(v[0], v[1]);
  int idx = 0;
  for(int i = 2; i < n; i++){
    while(idx < i){
      int d = v[i].X - v[idx].X;
      if(d*d < mini) break;
      else{
        s.erase({v[idx].Y, v[idx].X});
        idx++;
      }
    }
    auto st = s.lower_bound({v[i].Y - sqrt(mini), -INF}); // 후보군을 탐색한다
    auto en = s.upper_bound({v[i].Y + sqrt(mini), INF}); // 후보군을 탐색한다
    for(auto it = st; it != en; it++){ // 후보군 내의 점들과의 거리들 중에서 가까운 거리로 mini를 업데이트한다
      mini = min(mini, dist({it->Y, it->X}, v[i]));
    }
    s.insert({v[i].Y, v[i].X});
  }
  cout << mini << "\n";
  return 0;
}