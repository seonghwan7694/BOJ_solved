#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int N, NQ, P;
vector<pair<int, int>> query;
int arr[50001][51];
unordered_set<int> s;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> NQ >> P;
  for(int i = 1;i <= N; i++){
    for(int j = 1;j <= NQ; j++){
        cin >> arr[i][j];
    }
  }
  for(int i = 0, a, b; i < P; i++){
      cin >> a >> b;
      if(s.empty()){
          for(int j = 1; j <= N; j++){
              if(arr[j][a] == b){
                  s.insert(j);
              }
          }
      }else{
          for(auto iter = s.begin(); iter != s.end();){
              if(arr[*iter][a] != b){
                  iter = s.erase(iter);
              }else{
                  iter++;
              }
          }
      }
  }
  cout << s.size() << "\n";
  return 0;
}