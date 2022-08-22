#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
        int N;
        vector<bool> check;
        vector<int> prime;

        scanf("%d", &N);
        check.resize(N + 1, true);

        for (int i = 2; i * i <= N; i++) {
                if (check[i] == true) {
                        for(int j = i + i; j <= N; j += i)
                                check[j] = false;
                }
        }

        for (int i = 2; i < N + 1; i++) {
                if (check[i] == true) 
                        prime.push_back(i);
        }

        int cnt = 0, high = 0, low = 0, sum = 0;
        while (1) {
                if (sum >= N)
                        sum -= prime[low++];
                else if (high == prime.size())
                        break;
                else
                        sum += prime[high++];

                if (sum == N) cnt++;
        }
        printf("%d", cnt);
        return 0;
}