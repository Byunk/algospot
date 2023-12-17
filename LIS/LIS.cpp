#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
	
using namespace std;

int C, N;
int seq[500];
int cache[501]; // 0th element is a minus inf

int findLIS(int start) {
	int&ret = cache[start+1];
	if (ret != -1) return ret;

	ret = 1;
	for (int i = start+1; i < N; ++i) {
		if (start == -1 || seq[start] < seq[i]) {
			ret = max(ret, findLIS(i) + 1);
		}
	}
	return ret;	
}

void solve() {
	cin >> C;
	for (int i = 0; i < C; ++i) {
		memset(cache, -1, sizeof(cache));

		cin >> N;
		for (int j = 0; j < N; ++j) {
			cin >> seq[j];
		}
		cout << findLIS(-1)-1 << endl;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	solve();
}
