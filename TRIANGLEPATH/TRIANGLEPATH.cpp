#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
	
using namespace std;

int C, N;
int triangle[100][100];
int cache[100][100];

int findPath(int h, int w) {
	int& ret = cache[h][w];
	if (ret != -1) return ret;

	if (h == N-1) {
		return ret = triangle[h][w];
	}
	return ret = triangle[h][w] + max(findPath(h+1, w), findPath(h+1, w+1));
}

void solve() {
	cin >> C;
	for (int i = 0; i < C; ++i) {
		memset(cache, -1, sizeof(cache));

		cin >> N;
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k <= j; ++k) {
				cin >> triangle[j][k];
			}
		}
		cout << findPath(0, 0) << endl;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	solve();
}
