#include <iostream>
using namespace std;

int n, in_order[101010], post_order[101010], idx[101010];

/*

    2
1       3
인 오더 : 왼쪽 트리 -> 현재 노드 -> 오른쪽 트리
포스트 오더 : 왼쪽 트리 -> 오른쪽 트리 -> 현재 노드

*/

void get_pro_order(int instart, int inend, int poststart, int postend){
  if(instart > inend || poststart > postend){
    return;
  }
  int rootindex = idx[post_order[postend]];
  int leftsize = rootindex - instart;
  int rightsize = inend - rootindex;
  cout << in_order[rootindex] << " ";

  get_pro_order(instart, rootindex - 1, poststart, poststart + leftsize - 1);
  get_pro_order(rootindex + 1, inend, poststart + leftsize, postend -1);
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> in_order[i];
    idx[in_order[i]] = i;
  }
  for(int i = 1; i <= n; i++){
    cin >> post_order[i];
  }
  get_pro_order(1, n, 1, n);


  return 0;
}