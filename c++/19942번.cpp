#include <bits/stdc++.h>
#define lld long long int
using namespace std;

lld N, mp, mf, ms, mv;
lld p, f, s, v, c; // c is price
vector<tuple<lld, lld, lld, lld, lld>> food;
lld min_val = 1 << 13;
vector<int> vec;

int main(){
	ios::sync_with_stdio(false);
	cin >> N;
	cin >> mp >> mf >> ms >> mv;

	for(lld i = 0; i < N; i++){
		cin >> p >> f >> s >> v >> c;
		food.push_back({p, f, s, v, c});
	}

	for(lld bitset = 0; bitset <= ((lld)1 << N) - 1; bitset++){
		lld curp = 0, curf = 0 , curs = 0, curv = 0, curc = 0;
		for(lld selector = 0; selector < N; selector++){
			if(bitset & (1 << selector)){
				curp += get<0>(food[selector]); 
				curf += get<1>(food[selector]); 
				curs += get<2>(food[selector]); 
				curv += get<3>(food[selector]); 
				curc += get<4>(food[selector]); 
			}
			if(curp >= mp && curf >= mf && curs >= ms && curv >= mv && curc < min_val){
				min_val = curc;
				vec.clear();
				for(lld sel = 0; sel < N; sel++){
					if(bitset & ((lld)1 << sel)) vec.push_back(sel + 1);
				}
				break;
		}
		}
		
	}

	if(min_val == 1 << 13){
		cout << -1 << "\n";
		return 0;
	}	
	cout << min_val << "\n";
	sort(vec.begin(), vec.end());
    for(int i = 0; i < vec.size(); i++){
        if(i == vec.size() - 1) cout << vec[i] << "\n";
        else cout << vec[i] << " ";
    }

	return 0;
}

