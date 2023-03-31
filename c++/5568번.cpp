#include <bits/stdc++.h>
using namespace std;
vector<int> num;
set<int> s;
bool vis[10];
int n, k;

void func(int val, int depth){
	if(depth == k){
		s.insert(val);
		return;
	}
	
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			vis[i] = true;
			string tmp = to_string(num[i]);
			func(val * (int) pow(10, tmp.length()) + num[i], depth + 1);
			vis[i] = false;
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 0, tmp; i < n; i++){
		cin >> tmp;
		num.push_back(tmp);
	}
	
	sort(num.begin(), num.end());
	func(1, 0);

	cout << s.size() << "\n";
	return 0;
}

