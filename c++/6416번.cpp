#include <bits/stdc++.h>
using namespace std;

int a, b, cnt, root, indegree[100001], Way[100001];
set<int> Num;
vector<int> tree[100001];
bool flag;

// root 부터 모든 점으로 단 한번만 갈 수 있는지 체크
void Findway(int R){
	for (int child: tree[R]){
		// 이미 한번 갈 수 있는 점이나, root 자기 자신으로 가는 길이 있으면 틀린거.
		if(child==root||Way[child]==1){			
			flag = false;
			return;
		}
		// 해당 점을 가는 방법이 있음을 Way[child]=1로 저장.
		Way[child]=1;
		Findway(child);
	}
}
void IsItTree(){
	for(auto iter: Num){
		// root 제외 다른 점들은 indegree 가 1 이어야 해요!
		if(indegree[iter]>1){
			flag = false;
			return;
		}
		// indegree가 0 이면 root 입니다.
		else if(indegree[iter]==0) {
			if(root==-1)root=iter;
			// root 는 유일하게 존재해야 되요. 이미 root 가 있으면 틀린거.
			else{			
				flag=false;
				return;
			}
		}
	}
	// root가 없어도 안되죠.
	if(root==-1){	
		flag=false;
		return;
	}
	Findway(root);
}
int main(){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

while(1){
	cnt++;
	root = -1;
	for(auto iter: Num) tree[iter].clear();
	Num.clear();
	memset(indegree,0,sizeof(indegree));
	memset(Way,0,sizeof(Way));
	flag = true;
	cin >> a >> b;
	if(a<0&&b<0) break;
	// 시작부터 0 0 들어오면 tree 라고 말해주어야 합니다.... 이거 찾느라 오래걸렸어요...ㅠㅠ
	else if(a==0&&b==0) cout<<"Case " << cnt << " is a tree."<<'\n';
	else{
		Num.insert(a);
		Num.insert(b);
		tree[a].push_back(b);
		indegree[b]++;

		while(1){
			cin >> a >> b;
			if(a==0&&b==0){
				cout<<"Case "<< cnt;
				IsItTree();
				for(auto iter: Num){
					if(iter==root) continue;
					if(Way[iter]!=1) flag=false;
				}
				if(flag) cout << " is a tree." << '\n';
				else cout << " is not a tree." << '\n';
				break;
			}
			else{
				Num.insert(a);
				Num.insert(b);
				tree[a].push_back(b);
				indegree[b]++;
			}
		}
	}
}
return 0;
}