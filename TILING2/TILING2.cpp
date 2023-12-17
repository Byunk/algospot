#include <iostream>
#include <vector>
#include <string.h>
	
using namespace std;

int C, N;
const int D = 1000000007;
int cache[101];

int count(int n) {
	if (n == 0) return 1;
	if (n == 1) return 1;
	
	int& ret = cache[n];
	if (ret != -1) return ret;

	ret = (count(n-1) + count(n-2)) % D;
	return ret;
}

void solve() {
	cin >> C;
	for (int i = 0; i < C; ++i) {
		cin >> N;
		memset(cache, -1, sizeof(cache));
		cout << count(N) << endl;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	solve();
}
