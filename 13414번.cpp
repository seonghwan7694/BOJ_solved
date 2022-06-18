#include <bits/stdc++.h>
using namespace std;

int K, L;
unordered_map<string, int> us;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> K >> L;
  for(int i = 0; i < L; i++){
    string student_num; cin >> student_num;
    if(us.find(student_num) != us.end()){
      us[student_num] = i;
    }else{
      us.erase(student_num);
      us[student_num] = i;
    }
  }
  vector<pair<string ,int>> v(us.begin(), us.end());
  sort(v.begin(), v.end(), [](auto& a, auto& b) {return a.second < b.second;});
  int en = min(K, (int)v.size());
  for(int i = 0; i < en; i++){
    cout << v[i].first << "\n";
  }

  return 0;
}