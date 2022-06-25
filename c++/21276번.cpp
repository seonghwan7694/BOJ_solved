#include <bits/stdc++.h>
using namespace std;
int n, m, ind[1001], familyNum;
vector <int> graph[1001], childName[1001];
map <string,int> familyIdxMap;
map <int,string> familyNameMap;
vector <string> ancestor;

void topology_sort(string root){
  queue<int> q;
  q.push(familyIdxMap[root]);
  while(!q.empty()){
    auto x = q.front(); q.pop();
    for(auto nxt : graph[x]){
      if(--ind[nxt] == 0){
        childName[x].push_back(nxt);
        q.push(nxt);
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++){
    string s; cin >> s;
    familyIdxMap[s] = i;
    familyNameMap[i]= s;
  }
  
  cin >> m;
  for(int i = 0; i < m; i++){
    string a, b;
    cin >> a >> b;
    ind[familyIdxMap[a]]++;
    graph[familyIdxMap[b]].push_back(familyIdxMap[a]);
  }

  for(int i = 0; i < n; i++){
    if(!ind[i]){
      ancestor.push_back(familyNameMap[i]);
    }
  }
  sort(ancestor.begin(), ancestor.end());
  for(auto a : ancestor) topology_sort(a);
  cout << ancestor.size() << " ";
  cout << "\n";
  for(auto f : familyIdxMap){
    cout << f.first << ' ' << childName[f.second].size() << " ";
    vector<string> v;
    for(auto next : childName[f.second]) v.push_back(familyNameMap[next]);
    sort(v.begin(), v.end());
    for(auto ei : v) cout << ei << ' ';
    cout << "\n";
  }
}