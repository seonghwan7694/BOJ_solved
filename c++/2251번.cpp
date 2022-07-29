#include <bits/stdc++.h>
using namespace std;

int A, B, C;
bool visited[202][202][202];
vector<int> ans;
unordered_set<int> s;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);


  cin >> A >> B >> C;
  queue<tuple<int, int, int>> q;
  q.push({0, 0, C});
  while(!q.empty()){
    auto cur = q.front(); q.pop();
    int tmp_A = get<0>(cur); // 현재 A에 있는 물의 양
    int tmp_B = get<1>(cur); // 현재 B에 있는 물의 양
    int tmp_C = get<2>(cur); // 현재 C에 있는 물의 양
    if(visited[tmp_A][tmp_B][tmp_C]) continue;
    visited[tmp_A][tmp_B][tmp_C] = true;
    if(tmp_A == 0 and s.find(tmp_C) == s.end()){
      s.insert(tmp_C);
    }
    int d_A = A - tmp_A; // A에 넣을 수 있는 양
    int d_B = B - tmp_B; // B에 넣을 수 있는 양
    int d_C = C - tmp_C; // C에 넣을 수 있는 양

    // A -> B
    if(tmp_A != 0 and tmp_B != B){
      if(d_B >= tmp_A){ // B에 넣을 수 있는 양이 현재 A에 있는 양보다 더 많으면
        q.push({0, tmp_B + tmp_A, tmp_C}); // 물통 A에 있는 물 전부를 물통 B로!
      }else{ // B에 넣을 수 있는 양이 현재 A에 있는 양보다 적으면
        q.push({tmp_A - d_B, tmp_B + d_B, tmp_C});
      }
    }
    // A -> C
    if(tmp_A != 0 and tmp_C != C){
      if(d_C >= tmp_A){ // C에 넣을 수 있는 양이 현재 A에 있는 양보다 더 많으면
        q.push({0, tmp_B, tmp_C + tmp_A}); // 물통 A에 있는 물 전부를 물통 C로!
      }else{ // C에 넣을 수 있는 양이 현재 A에 있는 양보다 적으면
        q.push({tmp_A - d_C, tmp_B, tmp_C + d_C});
      }
    }
    // B -> C
    if(tmp_B != 0 and tmp_C != C){
      if(d_C >= tmp_B){ // C에 넣을 수 있는 양이 현재 B에 있는 양보다 더 많으면
        q.push({tmp_A, 0, tmp_C + tmp_B}); // 물통 B에 있는 물 전부를 물통 C로!
      }else{ // C에 넣을 수 있는 양이 현재 B에 있는 양보다 적으면
        q.push({tmp_A, tmp_B - d_C, tmp_C + d_C});
      }
    }
    // B -> A
    if(tmp_B != 0 and tmp_A != A){
      if(d_A >= tmp_B){ // A에 넣을 수 있는 양이 현재 B에 있는 양보다 더 많으면
        q.push({tmp_A + tmp_B, 0, tmp_C}); // 물통 B에 있는 물 전부를 물통 A로!
      }else{ // A에 넣을 수 있는 양이 현재 B에 있는 양보다 적으면
        q.push({tmp_A + d_A, tmp_B - d_A, tmp_C});
      }
    }
    // C -> A
    if(tmp_C != 0 and tmp_A != A){
      if(d_A >= tmp_C){ // A에 넣을 수 있는 양이 현재 C에 있는 양보다 더 많으면
        q.push({tmp_A + tmp_C, tmp_B, 0}); // 물통 C에 있는 물 전부를 물통 A로!
      }else{ // A에 넣을 수 있는 양이 현재 C에 있는 양보다 적으면
        q.push({tmp_A + d_A, tmp_B, tmp_C - d_A});
      }
    }
    // C -> B
    if(tmp_C != 0 and tmp_B != B){
      if(d_B >= tmp_C){ // B에 넣을 수 있는 양이 현재 C에 있는 양보다 더 많으면
        q.push({tmp_A, tmp_B + tmp_C, 0}); // 물통 C에 있는 물 전부를 물통 B로!
      }else{ // B에 넣을 수 있는 양이 현재 C에 있는 양보다 적으면
        q.push({tmp_A, tmp_B + d_B, tmp_C - d_B});
      }
    }
  }
  ans = vector<int>(s.begin(), s.end());
  sort(ans.begin(), ans.end());
  for(auto x : ans) cout << x << " ";
  return 0;
}