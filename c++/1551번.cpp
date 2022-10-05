#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> A;
vector<int> B;
string str, tmp;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> K >> str;
  str.push_back(',');

  for(auto& c : str){
    if(c != ',') tmp.push_back(c);
    else{
      A.push_back(stoi(tmp));
      tmp.clear();
    }
  }
  B = vector<int>(A.begin(), A.end());
  while(K--){
    B = vector<int>(A.size() - 1);
    for(int i = 0; i < A.size() - 1; i++){
      B[i] = A[i+1] - A[i];
    }
    A = vector<int>(B.begin(), B.end());
  }

  for(auto iter = B.begin(); iter != B.end(); iter++){
    cout << *iter;
    if(iter + 1 != B.end()){
      cout << ",";
    }
  }

  return 0;
}