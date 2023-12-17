#include <climits>
#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>
#include <algorithm>
#include <string.h>
	
using namespace std;

int C, N, S;
int nums[100];
int pSum[100], pSqSum[100];
int cache[101][11];

void precalc() {
	sort(nums, nums+N);
	pSum[0] = nums[0];
	pSqSum[0] = nums[0] * nums[0];

	for (int i = 1; i < N; ++i) {
		pSum[i] = pSum[i-1] + nums[i];
		pSqSum[i] = pSqSum[i-1] + nums[i] * nums[i];
	}
}

int minError(int start, int end) {
	int sum = pSum[end] - (start == 0 ? 0 : pSum[start-1]);
	int sqSum = pSqSum[end] - (start == 0 ? 0 : pSqSum[start-1]);
	int m = round((double)sum / (end - start + 1));

	int ret = sqSum - 2*m*sum + m*m*(end - start + 1);
	return ret;
}

int quantize(int start, int s) {
	if (start == N) return 0;
	if (s == 0) return 987654321;

	int& ret = cache[start][s];
	if (ret != -1) return ret;

	ret = INT_MAX;
	for (int i = 1; start+i <= N; ++i) {
		ret = min(ret, minError(start, start+i-1) + quantize(start+i, s-1));
	}
	return ret;
}

void solve() {
	cin >> C;
	for (int i = 0; i < C; ++i) {
		cin >> N >> S;
		for (int j = 0; j < N; ++j) {
			cin >> nums[j];
		}
		precalc();

		memset(cache, -1, sizeof(cache));

		cout << quantize(0, S) << endl;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	solve();
}
