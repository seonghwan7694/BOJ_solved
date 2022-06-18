#include <bits/stdc++.h>
using namespace std;

string st_meeting, en_meeting, en_streaming;
string t, name;
unordered_map<string, string> um;
int ans;

bool compare_string(string a, string b){
  string aaa, bbb;
  aaa += a[0]; aaa += a[1]; aaa += a[3]; aaa += a[4];
  bbb += b[0]; bbb += b[1]; bbb += b[3]; bbb += b[4];
  int aa = stoi(aaa);
  int bb = stoi(bbb);
  return aa <= bb;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> st_meeting >> en_meeting >> en_streaming;
  while(cin >> t >> name){
    if(compare_string(t, st_meeting)){
      um.insert({name, t});
    }
    if(compare_string(en_meeting, t) and compare_string(t, en_streaming)){
      if(um.find(name) != um.end()){
        um.erase(name);
        ans++;
      }
    }
  }
  cout << ans;
  return 0;
}