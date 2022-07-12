#include <bits/stdc++.h>
using namespace std;
#define INF 210000000
int N, M, a, b; // N : 끊어진 기타줄의 개수
vector<int> v1;
vector<int> v2;
int ans = INF;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  while(M--){
    cin >> a >> b;
    v1.push_back(a); // 6개
    v2.push_back(b); // 1개
  }

  a = *min_element(v1.begin(), v1.end());
  b = *min_element(v2.begin(), v2.end());
  cout << min({N*b, (N/6 + 1)*a, (N/6)*a + (N%6)*b}) << "\n";
  return 0;
}