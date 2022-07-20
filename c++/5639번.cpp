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

int tree[10101];

void postOrder(int start, int end){
  if(start >= end){
    return;
  }
  if(start == end - 1){
    cout << tree[start] << "\n";
    return;
  }
  int idx = start + 1;
  while(idx < end){
    if(tree[start] < tree[idx]){
      break;
    }
    idx++;
  }

  postOrder(start + 1, idx);
  postOrder(idx, end);
  cout << tree[start] << "\n";
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int num;
  int inputidx = 0;
  while(cin >> num){
    tree[inputidx++] = num;
  }
  postOrder(0, inputidx);

  return 0;
}