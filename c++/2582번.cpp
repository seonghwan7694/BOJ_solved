#include <bits/stdc++.h>
using namespace std;

int N;
int grid[40][40];
int ret=INT32_MAX;
double t = 1, lim = 0.005, k = 10, d = 0.9999;
std::mt19937_64 seed(410);
std::uniform_real_distribution<double> rng(0, 1);

int scoring(){
    int s = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            s += grid[i][j];
        }
    }
    return s;
}

void turn(int x, int y) {
	if (y == 0) {
		for (int i = 0; i < N; i++)
			grid[x][i] = 1 - grid[x][i];
	}
	else {
		for (int i = 0; i < N; i++)
			grid[i][x] = 1 - grid[i][x];
	}
}
 
void func() {
	for (int i = 0; i < N; i++) {
		int s = 0;
		for (int j = 0; j < N; j++)
			s += grid[j][i];
		if (s > (N / 2)) turn(i, 1);
	}
}

void simulated_annealing(){
    double e1, e2;
    int ori[40][40];
    while(t > lim){
        e1 = scoring();
        for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) ori[i][j] = grid[i][j];
        int pos = rand() % N;
        turn(pos, 0); func();
        e2 = scoring();
        double p = exp((e1-e2)/(k*t));
        if(p < rng(seed)) for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) grid[i][j] = ori[i][j]; 
        t *= d;
        ret = min(ret, scoring());
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++){
        string str;
        cin >> str;
        for(int j = 0; j < N; j++){
            grid[i][j] = (str[j] == 'T' ? 1 : 0);
        }
    }
    simulated_annealing();
    cout << ret << "\n";
    return 0;
}