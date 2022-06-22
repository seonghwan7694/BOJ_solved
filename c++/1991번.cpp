#include <bits/stdc++.h>
using namespace std;

int N;
vector<char> graph[300];
char lc[300];
char rc[300];

void preorder(char root){
  cout << root;
  if(lc[root]) preorder(lc[root]);
  if(rc[root]) preorder(rc[root]);
  return;
}

void inorder(char root){
  if(lc[root]) inorder(lc[root]);
  cout << root;
  if(rc[root]) inorder(rc[root]);
  return;
}

void postorder(char root){
  if(lc[root]) postorder(lc[root]);
  if(rc[root]) postorder(rc[root]);
  cout << root;
  return;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N;
  while(N--){
    char p, l, r; cin >> p >> l >> r;
    if(l != '.'){
      graph[p].push_back(l);
      lc[p] = l; 
    }
    if(r != '.'){
      graph[p].push_back(r);
      rc[p] = r;
    }
  }

  preorder('A'); cout << "\n";
  inorder('A'); cout << "\n";
  postorder('A'); cout << "\n";
  return 0;
}