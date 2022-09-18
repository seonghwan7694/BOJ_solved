#include <bits/stdc++.h>
using namespace std;

int N;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  int arr[N], line[N];
  for(int i = 0; i < N; i++){
    cin >> arr[i];
    line[i] = i;
  }


  do{
    int tmp[N] = {0};
    for(int i = 0; i < N; i++){
      for(int j = 0; j < i; j++){
        if(line[j] > line[i]) tmp[line[i]]++;
      }
    }

    for(int i = 0; i <= N; i++){
      if(i == N){
        for(int j = 0; j < N; j++){
          cout << line[j] + 1 << " ";
        }
        return 0;
      }
      if(arr[i] != tmp[i]) break;
    }
  }while(next_permutation(line, line + N));


  return 0;
} 