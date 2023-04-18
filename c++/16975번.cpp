
#include <iostream>
using namespace std;

long long A[100001];
long long segTree[400004];
long long lazy[400004];

long long initializeSegTree(int index, int start, int end) {
	if (start == end) segTree[index] = A[start];
	else {
		int mid = (start + end) / 2;
		segTree[index] = initializeSegTree(index * 2, start, mid) + 
			initializeSegTree(index*2+1, mid+1, end);
	}

	return segTree[index];
}

void propagateSegTree(int index, int start, int end) {
	if (lazy[index] != 0) {
		if (start != end) {
			lazy[index * 2] += lazy[index];
			lazy[index * 2 + 1] += lazy[index];
		}

		segTree[index] += (end - start + 1) * lazy[index];
		lazy[index] = 0;
	}
}

void updateSegTree(int index, int start, int end, int left, int right, int toAdded) {
	propagateSegTree(index, start, end);

	if (right < start || end < left) return;

	if (left <= start && end <= right) {
		lazy[index] += toAdded;
		propagateSegTree(index, start, end);
		return;
	}

	int mid = (start + end) / 2;
	updateSegTree(index * 2, start, mid, left, right, toAdded);
	updateSegTree(index * 2+1, mid+1, end, left, right, toAdded);
	segTree[index] = segTree[index * 2] + segTree[index * 2 + 1];
}

long long querySegTree(int index, int start, int end, int left, int right) {
	propagateSegTree(index, start, end);

	if (right < start || end < left) return 0;

	if (left <= start && end <= right) return segTree[index];

	int mid = (start + end) / 2;
	return querySegTree(index * 2, start, mid, left, right) +
		querySegTree(index * 2 + 1, mid + 1, end, left, right);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int i;

	int N;
	cin >> N;
	for (i = 1; i < N+1; i++) cin >> A[i];

	initializeSegTree(1, 1, N);

	int M;
	cin >> M;
	for (i = 0; i < M; i++) {
		int op;
		cin >> op;
		if (op == 1) {
			int a, b, k;
			cin >> a >> b >> k;
			updateSegTree(1, 1, N, a, b, k);
		}
		else {
			int x;
			cin >> x;
			cout << querySegTree(1, 1, N, x, x) << "\n";
		}
	}
}