#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
	
using namespace std;

int C, N;
int triangle[101][101];
int cost[101][101];
int cnt[101][101];

int path(int h, int w) {
	// count accumulate path cost
	if (h == N) {
		return cost[h][w] = triangle[h][w]; 
	}

	int& ret = cost[h][w];
	if (ret != -1) return ret;

	ret = triangle[h][w] + max(path(h+1, w), path(h+1, w+1));
	return ret;
}

int count(int h, int w) {
	if (h == N) return 1;

	int& ret = cnt[h][w];
	if (ret != -1) return ret;

	if (cost[h+1][w] > cost[h+1][w+1]) {
		ret = count(h+1, w);
	} else if (cost[h+1][w] < cost[h+1][w+1]) {
		ret = count(h+1, w+1);
	} else {
		ret = count(h+1, w) + count(h+1, w+1);
	}
	return ret;
}

void solve() {
	cin >> C;
	for (int c = 0; c < C; ++c) {
		cin >> N;
		
		memset(cost, -1, sizeof(cost));
		memset(cnt, -1, sizeof(cnt));

		for (int i = 1; i <= N; ++i) {
			for (int j = 1; j <= i; ++j) {
				cin >> triangle[i][j];
			}
		}

		path(1, 1);
		cout << count(1, 1) << endl;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	solve();
}
