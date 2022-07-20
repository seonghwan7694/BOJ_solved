#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;
#define ll long long
ll N, M;
ll A[101], C[101];
// dp[i] = 처음부터 i번째까지의 앱을 살펴보고, M 바이트를 확보하기 위한 최소의 비용
ll dp[10101010]; 
// 필요한 메모리 M 바이트를 확보하기위한 메모리

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M;
  for(int i = 1; i <= N; i++){
    cin >> A[i];
  }
  for(int i = 1; i <= N; i++){
    cin >> C[i];
  }

  ll size = 0;
  for(int i = 1; i <= N; i++) size += C[i];
  for(int i = 1; i <= N; i++){
    for(int j = size; j >= C[i]; j--){
      dp[j] = max(dp[j], dp[j - C[i]] + A[i]);
    }
  }
  int ans;
  for(int i = 0; i <= size; i++){
    if(dp[i] >= M){
      ans = i;
      break;
    }
  }
  cout << ans << "\n";
  return 0;
}