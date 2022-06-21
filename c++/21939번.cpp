#include <bits/stdc++.h>
using namespace std;

string cmd;
int P, L, x;
int N, M;

int probLevel[100'002];
set<int> probByLevel[102];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);



  /*
  x가 1인 경우 추천 문제 리스트에서 가장 어려운 문제의 번호를 출력한다.
  만약 가장 어려운 문제가 여러 개라면 문제 번호가 큰 것으로 출력한다.
  
  x가 -1인 경우 추천 문제 리스트에서 가장 쉬운 문제의 번호를 출력한다.
  만약 가장 쉬운 문제가 여러 개라면 문제 번호가 작은 것으로 출력한다.
  */


  cin >> N;
  while(N--){
    cin >> P >> L; // 문제 번호, 난이도
    probLevel[P] = L;
    probByLevel[L].insert(P); // 오름차순이 항상 보장됨
  }
  
  cin >> M;
  while(M--){
    cin >> cmd;
    if(cmd == "recommend"){
      cin >> x;
      if(x == 1){ // 가장 어려운 문제의 번호를 출력, 가장 어려운 문제가 여러 개라면 문제 번호가 큰 것으로 출력
        for(int i = 100; i >= 0; i--){
          if(probByLevel[i].empty()) continue;
          cout << *(prev(probByLevel[i].end())) << "\n";
          break;
        }
      }else if(x == -1){ // 가장 쉬운 문제를 출력, 가장 쉬운 문제가 여러 개라면 문제 번호가 작은 것으로 출력
        for(int i = 0; i <= 100; i++){
          if(probByLevel[i].empty()) continue;
          cout << *probByLevel[i].begin() << "\n";
          break;
        }
      }
    }else if(cmd == "add"){
      cin >> P >> L;
      probLevel[P] = L;
      probByLevel[L].insert(P);
    }else if(cmd == "solved"){
      cin >> P;
      probByLevel[probLevel[P]].erase(P);
    }
  }
  return 0;
}