#include <bits/stdc++.h>
using namespace std;

int vertex_num, edge_num;
vector<vector<int>> adj;
vector<int> visited_order;
vector<bool> is_cut_vertex;
int order, cut_cnt;

int FindCutVertex(int now_idx, bool is_root){
  visited_order[now_idx] = ++order;
  int min_order = visited_order[now_idx];
  int subtree_min_order, next_idx, children = 0;
  for(int i = 0; i < adj[now_idx].size(); i++){
    next_idx = adj[now_idx][i];
    if(visited_order[next_idx] == -1){
      children++;
      subtree_min_order = FindCutVertex(next_idx, false);

      if(!is_root and subtree_min_order >= visited_order[now_idx] and !is_cut_vertex[now_idx]){
        is_cut_vertex[now_idx] = true;
        cut_cnt++;
      }
      min_order = min(min_order, subtree_min_order);
    }else{
      min_order = min(min_order, visited_order[next_idx]);
    }
  }

  if(is_root and !is_cut_vertex[now_idx]){
    is_cut_vertex[now_idx] = (children >= 2);
    if(is_cut_vertex[now_idx]) cut_cnt++;
  }
  return min_order;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> vertex_num >> edge_num;

  adj = vector<vector<int>>(vertex_num + 1);
  visited_order = vector<int>(vertex_num + 1, -1);
  is_cut_vertex = vector<bool>(vertex_num + 1, false);

  int u, v;
  for(int i = 0; i < edge_num; i++){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for(int idx = 1; idx <= vertex_num; idx++){
    if(visited_order[idx] == -1) FindCutVertex(idx, true);
  }
  cout << cut_cnt << "\n";
  for(int i = 1; i <= vertex_num; i++){
    if(is_cut_vertex[i]) cout << i << " ";
  }
  cout << "\n";
  return 0;
}