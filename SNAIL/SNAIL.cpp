#include <iostream>
#include <vector>
	
using namespace std;

int C, N, M;
double cache[1001][1001];

double count(int m, int n) {
	// m 일 남고, n 높이일때, 끝까지 도달할 확률
	if (n >= N) return 1.0;
	if (m == 0) return 0.0;

	double& ret = cache[m][n];
	if (ret != -1.0) return ret;
	
	ret = 0.75 * count(m-1, n+2) + 0.25 * count(m-1, n+1);
	return ret;
}

void solve() {
	cin >> C;
	for (int c = 0; c < C; ++c) {
		cin >> N >> M;
		for (int i = 0; i < 1001; ++i) {
			for (int j = 0; j < 1001; ++j) {
				cache[i][j] = -1.0;
			}
		}
		cout << fixed;
		cout.precision(10);
		cout << count(M, 0) << endl;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	solve();
}
